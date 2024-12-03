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

  vector<int> box(n);
  vector<int> w(n);

  rep(i,n)cin >> box[i];
  rep(i,n)cin >> w[i];

  vector<priority_queue<int, vector<int>, greater<int> >> dup(n+1);
  map<int,int> q;
  int ans = 0;

  rep(i,n){
    int a = box[i];
    int b = w[i];
    dup[a].push(b);
    if(dup[a].size()>1){
      ans += dup[a].top();
      dup[a].pop();
    }
  }


  cout << ans << endl;
  return 0;
}