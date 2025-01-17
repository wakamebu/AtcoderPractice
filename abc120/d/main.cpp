/*
N 個の島と M 本の橋があります。
i 番目の橋は A[i] 番目の島と B[i] 番目の島を繋いでおり、双方向に行き来可能です。

はじめ、どの 2 つの島についてもいくつかの橋を渡って互いに行き来できます。

調査の結果、老朽化のためこれら M 本の橋は 1 番目の橋から順に全て崩落することがわかりました。

「いくつかの橋を渡って互いに行き来できなくなった 2 つの島の組 (a, b) (ただしa < b) の数」を不便さと呼ぶことにします。
初期状態における不便さは、どの 2 つの島についても互いに行き来可能なので 0 です。

各 i について、i 番目の橋が崩落した直後の不便さを求めてください。(i = 1, 2, ..., M)

2 ≤ N ≤ 10^5  
1 ≤ M ≤ 10^5
1 ≤ A[i] < B[i] ≤ N
*/

/*
union-find を使う。最後の辺から順番に繋げていけば、完成状態から始めて 1 番目の橋から順に崩落していく状況を逆再生で見ていくことができる
。
不便さのカウントについて、頂点同士の組をひとつひとつチェックしていくには流石に時間オーバーする。
    → 独立した木の頂点数がわかればよさそう。

今　T[1], T[2], ..., T[k] の k 個の独立した木になっているとする。
それぞれの木について、頂点数が C[1], C[2], ..., C[k] になっていたら、
T[1] に属するある頂点について、互いに行き来できない頂点は (N - C[1]) 個。T[1] に属する頂点数が C[1] なので、合計では C[1] x (N - C[1]) 個。
それぞれの木について考えていくのと頂点の組を二重で数えているので 2 で割って、
    「不便さ」= Σ C[k] x (N - C[k]) / 2
となる。
    Σ C[k] = N なので、
    Σ C[k] x (N - C[k]) /2  = {N^2 - Σ (C[k]^2)} / 2

ただし Σ (C[k]^2) は 独立木の数が最大 N 個なので、毎回計算するのは大変。
なので遷移を考えてみる。
逆再生の過程で橋 i が追加されてたとき、T[p] と T[q] が合併したとする。
そうするとひとつ手前の状態から C[p]^2 と C[q]^2 が減少して、(C[p] + C[q])^2 が増加することになる。
    +(C[p] + C[q])^2 - C[p]^2 - C[q]^2 = +(2 x C[p] x C[q])
だけ変化する。
ここは引き算用の項だし、全体が 1 / 2 になるのも考慮して、 
    今の「不便さ」 = もう一つ崩落したときの「不便さ」 -  C[p] x C[q]
*/



#include <bits/stdc++.h>
using namespace std;

// ここはメインより上に記述する部分。
struct UnionFind {
    // par[a] = b の場合、「aの親が、bである」という意味。木があったとき、木の根側の頂点が親です。
    // pair型にして、第一要素で親の管理、第二要素で同じ木の頂点数の管理を行う
    vector<pair<int, int>> par;    
    
    // N 個の頂点について、最初は「 N 個全てにおいて自分自身が親である、すなわち自分は木の根である」として初期化。
    // 第二要素については、自分自身しか含まない木なので、頂点数は 1 を代入。
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++){
            par[i].first = i;
            par[i].second = 1;
        }
    }

    // データxが木の根の場合は、x（根）を返す。
    // データxが木の根でない場合は、parで親を再帰的にたぐり、最終的に親のおおもと（根）を返す。
    pair<int, int> root(int x) {           // データxが属する木の根を再帰で得る。：root(x) = {xの木の根}
        if (par[x].first == x){
            return par[x];
        }
        return par[x] = root(par[x].first);
    }
    
    // xの根である所のr_xと、yの根である所のr_yが同じならば、そのまま何も操作しない。r_xとr_yが同じでないときは、xの根r_xをyの根r_yにつける。
    // すなわちこの関数は，根が同じでない(＝同じ木でない)二つの木を併合する。
    void unite(int x, int y) { 
        int rx = root(x).first; //xの根をrx
        int ry = root(y).first; //yの根をry

        if (rx == ry){
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        }
        par[rx].first = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        par[ry].second += par[rx].second;  // より深い根とした方である根 ry の方に、根 rx の頂点数を足す 
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y) {
        int rx = root(x).first;
        int ry = root(y).first;
        return rx == ry;  // この式が成り立てばtrueが返り値、不成立ならfalseが返り値
    }
};   // structなので ; が必要。


// ここからメイン。
int main() {
    //  N 個の頂点。M 本の辺
    int N, M;
    cin >> N >> M;

    // 辺の情報を入力。
    pair<int, int> AB[M];
    for(int i = 0; i < M; i++) {
        cin >> AB[i].first;   // 頂点A
        cin >> AB[i].second;  // 頂点B

        // 問題文は頂点番号 1 スタートなので、ひとつずらす
        AB[i].first--;
        AB[i].second--;
    }

    // N 個すべての頂点が自分か「根」だと初期化した状態で vector<pari<int, long long>> par が生成される。
    UnionFind tree(N);

    // すべての橋が崩落した最終的な状態での「不便さ」を計算して格納する。
    vector<long long> ans(M);  // 1 番目の橋から M 番目の橋まで順に崩落していくのを後ろから格納していく。
    // 初項を入力しておく。ここから遷移で計算していく。
    // C[k] = 1 の木が N 本あるので、 Σ (C[k]^2) = N 
    ans.at(M-1) = 1LL * N * (N - 1) / 2;     // 1LL * N * (N - 1) の書き方が必須。 1LL が無いとオーバーフローして負の数になるし、1LL * (N*N - N) でもオーバーフローしてしまう。

    // Union-find を、辺の最後から順に実行
    for (int i = M-1; i >= 1; i--) {  
        // 島 x と 島 y をつなぐ橋について、もともと同じ木の内部の橋なら特に何もしない。
        // 別の木なら色々と処理する。
        int  x, y;
        x = AB[i].first;
        y = AB[i].second;

        if (tree.same(x, y)){    // 2つのデータx, yが属する木が同じの場合。独立した木の状況に変化無し。
            ans.at(i-1) = ans.at(i);    // ans の値はひとつ右の添え字位置と同じ
            continue;
        } 

        else {   // 別の木の場合
            // ans の値はひとつ右の添え字位置の値から、頂点 x の木の頂点数 tree.root(x).second と 頂点 y の木の頂点数をかけた分だけ減少
            ans.at(i-1) = ans.at(i) - 1LL * tree.root(x).second * tree.root(y).second;
            tree.unite(x, y);    // 2つの木を統合する
        }
    }

    // 回答
    for (auto item : ans){
        cout << item << endl;
    }

    return 0;
}

