#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,k;
  cin >> n >> k;
  queue<int> A;
  rep(i,n){
    int a;
    cin >> a;
    A.push(a);
  }

  int res = 0;
  int K = k;
  rep(i,100000){
    int now = A.front();
    int size = A.size();
    //cout << now <<endl;
    if(k >= now && size>0){
    k -= now;
    A.pop();
    }else if(size>0){
      res++;
      k = K;
    }else if(size == 0){
    res++;
    break;
    }
  }

  cout << res << endl;
  return 0;
}