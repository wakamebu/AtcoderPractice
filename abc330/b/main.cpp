#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,l,r;
  cin >> n >> l >>r;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> memo;// key:a[i] value:ans

  vector<int> ans;
  rep(i,n){
    int k = a[i];
    if(k<l)ans.push_back(l);
    else if(k>r)ans.push_back(r);
    else{
      if(memo.count(k)){
        ans.push_back(memo[k]);
        continue;
      }
      memo[k] = k;
      ans.push_back(k);
    }
  }

  for(auto x:ans)cout << x << " ";
  cout << endl;
  return 0;
}




//int answer() {
//    int n, l, r;
//    cin >> n >> l >> r;
//    vector<int> a(n);
//    rep(i, n) cin >> a[i];
//    rep(i, n) cout << clamp(a[i], l, r) << " \n"[i == n - 1];
//}