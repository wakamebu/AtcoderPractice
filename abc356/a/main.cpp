#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,l,r;
  cin >> n >> l >> r;
  vector<int> A(n);


  for(int i = 0; i<n; i++){
  A[i] = i + 1;
  }

  reverse(A.begin() + (l - 1), A.begin() + r);


  for (int i = 0; i < n; i++) {
        if(i<n-1)cout << A[i] << " ";
        else cout << A[i];

    }
    cout << endl;

}
