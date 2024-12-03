/*
https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1
N 個の電球が廊下の西側から東側に一列に並んでいる．各電球は明かりがついているか，ついていないかのいずれかの状態である．
そしてあなたはスイッチを持っている。
このスイッチは連続した電球を指定すると，指定された電球のうち，明かりがついている電球全てを明かりがついていない状態にし，明かりがついていない電球全てを明かりがついている状態にする．
ただしスイッチは老朽化のため，1 回しか使用できない．

皆は明かりがついている電球とついていない電球が交互に並んだ列（このような電球の列を交互列と呼ぶ）が好きである．
そこで，このスイッチを必要ならば 1 回だけ使って，できるだけ長い交互列を含む電飾を作ることにした．
交互列の長さとして考えられるものの最大値を求めよ。

2 ≦ N ≦ 10^5 
c[i] = 0 or 1  // i 番目の電球について明かりついているか否か。0 は消灯状態、1 は点灯状態である。 
*/

/*
ある電球 i をスイッチで on/off の切り替えを行う場合、できるだけ長い交互列を作りたいのなら、もともと電球 i につながっている電球列はまるごと切り替えた方がよい。

例えば最初の電球状態が 
    0  1   1   1 0   0 1 0 1 0 1 0   0 0 0
の場合なら。
    {0 1} {1} {1 0} {0 1 0 1 0 1 0} {0 0 0}
3番目のまとまりをスイッチを切り替えて、
→  {0 1} {1} [0 1] {0 1 0 1 0 1 0} {0 0 0}  
       = {0 1} {1 0 1 0 1 0 1 0 1 0} {0 0 0}
とするのがよい。

また、まとまりを on/off の切り替えすると、生成される交互列の長さは、
    「ひとつ左のまとまりの長さ」+「切り替えをおこなったまとまりの長さ」+「ひとつ右のまとまりの長さ」
が生成される。
*/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}

int main() {
    int N;
    cin >> N;

    vector<int> line(N, 0);     // まとまりを格納するベクトル。最大 N 個。初期値は 0 で埋めておく
    int idx = 0;  // ベクトル line の添え字管理。初期は 0 です。

    int now_length;  // 現在伸びている交互列の長さ
    int now_c;       // 交互列になっているかどうかを判定するための、最新の点灯状態 (0 or 1 の値)

    // now_c の初項として c[0] を代入
    int c0;
    cin >> c0;
    now_c = c0;
    now_length = 1;  // 現在伸びている交互列の長さについて、初項は 1 です

    for (int i = 1; i < N; i++){
        int c;
        cin >> c;

        // 交互列の場合
        if (c != now_c){
            now_length++;   // 交互列の長さをひとつ増加
            now_c = c;      // 最新の点灯状態を更新
        }

        // 同じ点灯状態で交互列ではない場合
        else if (c == now_c){
            // 今の now_length をベクトル line に格納
            line.at(idx) = now_length;
            idx++;      // 添え字管理 idx を増加させて、次の格納の準備

            // 
            now_length = 1;  // 交互列の長さを 1 から始め直し
            now_c = c;       // 最新の点灯状態を更新
        }
    }

    // N 個の電球の状態を入力し終わったら、now_length も ベクトル line に格納
    line.at(idx) = now_length;

    // 最後に できるだけ長い交互列をチェック。
    // スイッチ切り替えした時、ベクトル line の連続する 3 つの要素の総和が新たに生成する交互列の長さになる。
    // ベクトル line には代入された要素数が idx までであり、それ以降は 0 で埋まっている。
    // idx までのfor文にしようかと思ったが、idx = 0 or 1 だと代入された要素数が 2 個以下なので条件分けが面倒。おとなしく N までfor文を行う。
    int ans = 0;

    if (N == 2){  // N = 2 だと、要素の指定が3つとれない。よって直接答えを入力
        ans = 2;  // 必ず長さ 2 の交互列を生成可能 
    }

    else{    // N = 3 以上なら通常の処理
        for (int i = 0; i < N-2; i++){  // 連続する 3 要素なので、< N-2 までfor文を行う 
            int temp = line.at(i) + line.at(i+1) + line.at(i+2);        
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
    return 0;
}
