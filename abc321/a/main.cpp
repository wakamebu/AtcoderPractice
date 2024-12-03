#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string n;
  cin >> n;

  for(int i = 1;i<n.size();i++){
    if(n[i-1]<=n[i]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}