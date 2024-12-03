#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  rep(i,n) cin >> d[i];

  int sum = 0;
  rep(i,n){
    sum += d[i];
  }

  int ans = (sum + 1)/2;



  rep(i,n){
      if(ans <= d[i]){
        cout << i +1 << ' ' << ans << endl;
        return 0;
      }
      ans -= d[i];
    }
    return 0;
}