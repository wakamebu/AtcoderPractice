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

  map<int,queue<int>> ans;

  rep(i,3*n){
    int a;
    cin >> a;
    ans[a].push(i+1);
  }

  vector<P> c;
  for(auto x :ans){
    x.second.pop();
    c.emplace_back(make_pair(x.second.front(),x.first));
  }

  sort(c.begin(),c.end());

  for(auto x : c){
    cout << x.second << " ";
  }

  cout << endl;
  return 0;
}