#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int di[]= {-1,0,1,0};
const int dj[] = {0,1,0,-1};

int main() {
  int h,w,n;
  cin >> h >> w >>n;
  vector<string> s(h, string(w,'.'));

  int i = 0, j= 0, v =0;
  rep(ti,n){
    if(s[i][j]=='.'){
      s[i][j]='#';
      v += 1;
    }else{
      s[i][j]='.';
      v+=3;
    }
    v%= 4;
    i += di[v]; j+= dj[v];
    i = (i+h)%h;
    j = (j+w)%w;
  }

  rep(i,h)  cout << s[i] << endl;
  return 0;
}