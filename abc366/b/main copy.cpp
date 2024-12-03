#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    int m = 0, cnt = 0;
    rep(i,n){
        cin >> vec[i];
        if(vec[i].size() == m) cnt++;
        if(vec[i].size() > m){
            m = vec[i].size();
            cnt = 1;
        }
    }
    vector<queue<char>> ans(m);
    rep(i,m - 1){
        rep(j,n){
            if(vec[n - j - 1].size() > i) ans[i].push(vec[n - j - 1][i]);
            else ans[i].push('*');
        }
    }
    int i = m - 1;
    rep(j,n){
            if(vec[n - j - 1].size() > i){
                ans[i].push(vec[n - j - 1][i]);
                cnt--;
            }
            else if(cnt > 0) ans[i].push('*');
            else break;
        }
    rep(i,m){
        while(ans[i].size()){
            cout << ans[i].front(); ans[i].pop();
        }
        cout << endl;
    }
    return 0;
}