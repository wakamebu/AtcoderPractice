#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    long long B;
  cin >> B;
  for (int A = 1; A <= 15; A++) {
    long long x = 1;
    for (int i = 0; i < A; i++) x *= A;
    if (x == B) {
      cout << A << endl;
      exit(0);
    }
  }
  cout << "-1" << endl;
}