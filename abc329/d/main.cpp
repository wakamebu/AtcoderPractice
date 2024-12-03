#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;

  map<int,int> A;

  int nowh = 0;
  int nowt = 0;
  int q;
  rep(i,m){
    cin >> q;
    A[q]++;
    if(A[q]> nowt){
      nowt = A[q];
      nowh = q;
    }else if(A[q] == nowt && nowh > q){
      nowh = q;
    }
    cout << nowh << '\n';
  }

  return 0;
}