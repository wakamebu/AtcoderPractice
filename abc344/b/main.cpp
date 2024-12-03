#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  vector<int> A;
  rep(i,100){
    int b = 0;
    cin >> b;
    A.push_back(b);
    if(b == 0)break;
  }

  int sz = A.size();

  for (int i = sz - 1; i >= 0; --i) {
    cout << A[i] << endl;
}
  return 0;
}