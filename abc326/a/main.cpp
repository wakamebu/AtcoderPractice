#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
  int x,y;
  cin >> x >> y;
  if(x-3<=y && y<=x+2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}