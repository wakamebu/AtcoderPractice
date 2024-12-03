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

  vector<vector<int>> grid(n,vector<int>(n,0));

  int cx = n/2, cy = n/2;
  int num = n*n;

  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int dir = 3;// 0:R 1:D 2:L 3:U

  grid[cx][cy] = num;
  int x = cx;
  int y = cy;

  int cnt = 1;
  while(num>0){
    rep(s,2){
      rep(i,cnt){
        x += directions[dir].first;
        y += directions[dir].second;
        num --;
        if(num <=0) break;
        grid[x][y] = num;
      }
      dir = (dir+1)%4;
    }
    cnt++;
  }

  
  rep(i,n){
    rep(j,n){
      if(grid[i][j] == n*n)cout << "T" << " ";
      else if(j != n-1)cout << grid[i][j] << " ";
      else if(j == n-1)cout << grid[i][j];
    }  cout << endl;
  }


  return 0;
}