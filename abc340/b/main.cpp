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
  vector<int> A;

  rep(i,n){
    int x,y;
    cin >> x >> y;
    if(x == 1){
    A.emplace_back(y);
    }else if(x == 2){
      cout << A.end()[-y] <<endl;
    }
  }


  return 0;
}