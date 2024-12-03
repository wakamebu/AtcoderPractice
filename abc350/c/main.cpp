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
  //Swap関数を使う
  //配列Aを正しい場所に送る

  vector<int> a(n+1);
  rep(i,n){
    cin >>a[i+1]; // index:1 宣言もn+1
  }

//正しい数字がどこにあるかを配列にする
  vector<P> ans;
  for(int i = 1; i <= n; i++){
    while (a[i] != i){
      int j = a[i];
      swap(a[i],a[j]);
      ans.emplace_back(i,j);
    }
  }
  cout << ans.size() << endl;

  for(auto [i,j]:ans) cout << i << " " << j << endl;
  return 0;

}

