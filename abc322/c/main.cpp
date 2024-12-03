#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;

  vector<int> sp(m);
  rep(i,m)cin >> sp[i];

  sort(sp.begin(),sp.end());

  int it = 0;
  int res = 0;
  for(int i = 1 ; i<n+1 ; i++ ){
    while(res<i){
      res = sp[it];
      it++;
    }
    cout << (res -i) << endl;
  }

  return 0;
}