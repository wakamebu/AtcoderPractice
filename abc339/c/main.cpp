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

  vector<int> B(n);
  rep(i,n) cin >> B[i];

  priority_queue<ll, vector<ll>, greater<ll> > q;
  ll sum = 0;
  rep(i,n){
    sum += B[i];
    q.emplace(sum);
  }

  ll ans = 0;
  if(q.top() >0){
    cout << sum << endl;
    return 0;
  }
  ans = abs(q.top());
  cout << ans+sum << endl;
  return 0;
}