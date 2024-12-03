#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

bool check(int n){
  int c100=n/100;
  int c10=n/10%10;
  int c1=n%10;
  return c100*c10==c1;
}

int main() {
  int n;
  cin >> n;

  for(int i = n;i<920;i++){
    if(check(i)){
      cout << i << endl;
      return 0; 
    }
  }
}