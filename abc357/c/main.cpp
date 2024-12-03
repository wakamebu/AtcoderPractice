#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

  //i-1のグリッドを描く関数

void draw(vector<vector<char>>& grid, int x , int y, int size){
  if(size == 1){
  grid[x][y] = '#';
  return;
}

int newSize = size/3;
rep(i,3){
  rep(j,3){
    if(i ==1 && j == 1){
      for(int dx = 0; dx< newSize; ++dx){
        for(int dy = 0; dy < newSize; ++dy){
          grid[x+i*newSize +dx][y+j*newSize+dy]='.';
        }
      }
      }else{
      draw(grid,x+i * newSize,y+j*newSize,newSize);
      }
    }
  }
}


int main() {
  int n;
  cin >> n;
  int size = pow(3,n);

  vector<vector<char>> grid(size, vector<char>(size, ' '));

  draw(grid,0,0,size);
  
  rep(i,size){
    rep(j,size){
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}