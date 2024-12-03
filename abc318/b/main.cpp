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

  vector<vector<int>> imos(101,vector<int>(101,0));
  
  rep(i,n){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    imos[a][c]++;
    imos[b][d]++;
    imos[a][d]--;
    imos[b][c]--;
  }



  int ans = 0;
  rep(i,101)rep(j,100)imos[i][j+1] += imos[i][j];
  rep(i,100)rep(j,101)imos[i+1][j] += imos[i][j];
  rep(i,100)rep(j,100)if(imos[i][j]>0) ans++;
  

  cout << ans << endl;
  return 0;
}