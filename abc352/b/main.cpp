#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string S,T;
  cin >> S >> T;
  int size = S.size();

  int it = 0;
  for(int i = 0; i<size ; i++){
    while(S[i] != T[it]){
      it++;
    }
    if(i+1 != size){
      cout << it+1 << " ";
    }else if(i+1 == size){
      cout << it+1 <<endl;
    }it++;
  }
  return 0;
}

//    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];