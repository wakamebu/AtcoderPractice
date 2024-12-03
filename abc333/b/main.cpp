#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  char a,b,c,d;
  cin >> a >> b >> c >>d;

  auto near = [&](char x, char y){
    if(x > y) swap(x,y);
    return y-x == 1 or y - x == 4;
  };

  if(near(a,b) == near(c,d)){
    cout << "Yes" <<endl; 
  }else cout << "No" <<endl;



  return 0;
}