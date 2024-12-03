#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int k;
  cin >> k;

  map<char,int> sell;

  rep(i,26){
    char A = 'A';
    A += i;
    int C;
    cin >> C;
    sell[A] = C; 
  }

  ll sum = 0;
  for(auto x :sell){
    sum += x.second;
  }

  cout << ans << endl;
  return 0;
}