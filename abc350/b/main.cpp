#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> tooth(n,1);
  
  int f = 0;
  rep(i,q){
    cin >> f;
    f--;
    if(tooth[f] == 1){
      tooth[f]--;
    }else if(tooth[f] == 0){
      tooth[f]++;
    }
  }

  int res =0;
  rep(i,n){
    if(tooth[i] == 1){res++;}
  }

  cout << res << endl;
  return 0;
}