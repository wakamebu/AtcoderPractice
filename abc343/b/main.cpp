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
  vector<vector<int>> ans(n,vector<int>(n));
  
  rep(i,n){
    rep(j,n){
      cin >> ans.at(i).at(j);
      }
  }

  int count = 0;
  rep(i,n){
    count = 0;
    rep(j,n){
      if(ans.at(i).at(j)==1){
        if(count == 0){cout << j+1;
        count ++;
        }else{
          cout << " " << j+1; 
        }
      }
    }if(count >0)cout << endl;
  }if(count == 0)cout << endl;
  return 0;
}