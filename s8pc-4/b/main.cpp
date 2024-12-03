#include <bits/stdc++.h>
using namespace std;

/*
N 個の建物が左から一連に並んでいる。建物 i の高さはa[i]である。
左から見たとき、N 個のうちどれでもいいのでK個以上の建物について、自分より左により高い建物が無い状態になってほしい。(高さ等しいはアウト)
それぞれの建物について、より高くする操作は可能だが、低くすることはできない。
合計でどれだけ高くすれば目標達成できるか。

1 ≤ K ≤ N ≤ 15
1 ≤ a[i] ≤ 10^9  ... long long型
*/

/*
とりあえずbitが1になっている建物について、自分より左に大きい建物がないように高くしよう。
bitが1になっている数の合計がK以上とすればよい。
*/


int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> a(N);
    for (int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    // heighten_a に建物を高くする処理後の値を格納する。
    vector<long long> heighten_a(N);

    // 回答で出力する建物高くする操作の回数。min(a,b)で比べるので、初期値はありえないほど大きくしておく。
    long long ans = 10000000000000;

    // N個の建物について、どれを高くするのか 2^N 通りの組み合わせ。
    for (int i = 0; i < (1 << N); i++){ 
        int bit[15]; // 2^N の二進数変換後の数列が、収まる長さ(つまりN以上)のコンテナならOK vectorを使うことも
        int K_flag = 0;   // bit が1になっている数が合計K以上必要なので、合計計算用にK_flagを使用。毎回0で初期化
        long long total_how_heighther = 0;  // 今回の組み合わせで建物を高くするとき、合計でどれだけ高くする必要があるか。毎回初期化

        // 整数 i をもとに、二進数変換を行う。
        for (int k = 0; k < N; k++){   
            int Div = (1 << k);         // (1 << k) = 2^k という意味
            bit[k] = (i / Div) % 2;
            // bit[k]が1ならK_flagに足していく。0の場合は足しても意味ないので、全部足すという処理でOK。
            K_flag += bit[k];
        }

        // K_flag < Kなら条件を満たさない。continueで、次のbitの組み合わせに進む。
        if (K_flag < K){
            continue;
        }

        // ここにきたら K_flag >= K が成立している。
        // heighten_a に建物を高くする処理後の値を格納する。毎回オリジナルのaで初期化。
        heighten_a = a;

        // k = 1, 2, ... N-1 について、bit[k]で建物を高くするかどうかチェックしていく。ちなみに k = 0 は自分の前に建物無いので、そもそも高くする必要がない。
        for (int k = 1; k < N; k++){
            // bit[k] = 0 の建物では、そもそも建物の高さを高くする操作は必要ない。continueで次のkへ進む。
            if (bit[k] == 0){
                continue;
            }
            // continueを躱したら、bit[k] = 1 の建物。
            // まずはスタートから添え字位置 k-1 までの範囲で、最大の建物の高さを計算する。
            long long highest_beyond_k = 0;
            for (int r = 0; r < k; r++){
                highest_beyond_k = max(highest_beyond_k, heighten_a.at(r));
            }

            // 建物をどれくらい高くするかの値。毎回初期化
            long long how_heigher = 0;
            
            // a[k]での高さが highest_beyond_k　よりも大きければ特に建物高くする操作は必要ない。continueで次のkへ進む。
            if (heighten_a.at(k) > highest_beyond_k){
                continue;
            }
            else if (heighten_a.at(k) <= highest_beyond_k){
                how_heigher = highest_beyond_k - heighten_a.at(k) + 1; // 高さが等しい状態では駄目なので、+1 をつける。
                heighten_a.at(k) = highest_beyond_k + 1;    // 高くする操作を行なったので heighten_a を更新する。
                total_how_heighther += how_heigher;  // 回答の方も高くした分だけ増やしておく。
            }
        }

        ans = min(ans, total_how_heighther);
    }

    std::cout << ans << endl;

}


