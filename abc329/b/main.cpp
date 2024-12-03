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

  priority_queue<int> q;

  rep(i,n){
    int a;
    cin >> a;
    q.push(a);
  }

  int ans = q.top();
  q.pop();
  while(ans == q.top()){
    q.pop();
  }
  ans = q.top();

  cout << ans << endl;
  return 0;
}