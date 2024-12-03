#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> H(N);
    for(auto &h : H) cin >> h;

    // 前処理：各ビルjに対して、左側で最後にH[k] > H[j]となるkを求める
    vector<int> last_greater(N +1, 0); // 1-based indexing
    stack<int> s;

    for(int j=1; j<=N; ++j){
        while(!s.empty() && H[j-1] > H[s.top()-1]){
            s.pop();
        }
        if(s.empty()){
            last_greater[j]=0;
        }
        else{
            last_greater[j]=s.top();
        }
        s.push(j);
    }

    // 差分配列の構築
    vector<int> D(N +2, 0); // 1-based indexing

    for(int j=1; j<=N; ++j){
        if(j ==1){
            continue; // i < j, so no i for j=1
        }
        int L = last_greater[j];
        if(L ==0){
            L =1;
        }
        int R =j-1;
        if(L <= R){
            D[L] +=1;
            D[R+1] -=1;
        }
    }

    // 累積和を取って各iのカウントを求める
    vector<int> counts(N +1, 0); // 1-based indexing
    int current =0;
    for(int i=1; i<=N; ++i){
        current += D[i];
        counts[i]=current;
    }

    // 出力
    for(int i=1; i<=N; ++i){
        cout << counts[i] << (i !=N ? " " : "\n");
    }

    return 0;
}
