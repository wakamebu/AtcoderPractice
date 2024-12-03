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
  map<int,int> ans;
  map<int,int> ans2;
  int a;


  rep(i,n){
    int num = i+1;
    cin >> a;
    ans[num] = a;
    ans2[a] = num;
  }

  int head = 0;
  for(auto x :ans){
    if(x.second == -1){
    cout << x.first ;
    head = x.first;
    ans.erase(x.second);
    }
  }
  
  rep(i,n-1){
    int res = 0;
    res = ans2[head];
    cout << " " << res ;
    head = res;
  }
  
  cout << endl;
  return 0;
}