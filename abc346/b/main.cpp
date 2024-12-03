#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int w,b;
  cin >> w >> b;
  int wb = w + b;
  string S = "wbwbwwbwbwbw";

  rep(i,10){
  S += S;
  }

  rep(i,S.size()){ 
  int  wcount = 0;
  int bcount = 0; 
    rep(j,wb){
      if (S[i+j] == 'w' ){
        wcount++;
      }else if(S[i+j] == 'b'){
        bcount++;
      }
    }if(wcount == w && bcount == b){
      cout << "Yes" <<endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}