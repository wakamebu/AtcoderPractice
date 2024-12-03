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

  for(int i = 1; i < n+1 ; i++){
    if(i %3 == 0){
      cout << "x";
    }else{
      cout << "o";
    }
  }
  cout << endl;
  return 0;
}