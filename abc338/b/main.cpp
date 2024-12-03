#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string s;
  cin >> s;
  priority_queue<int> q; 
  char ans;
  int it = 0;
  
  rep(i,26){
    char l = 'a';
    l += i;
    int res = 0;
    rep(j,s.size()){
    if(s[j] == l)res++;
    }
    q.emplace(res);
    if(it < q.top()){
    ans = l;
    it = q.top();
    }
  }

  cout << ans << endl;
  return 0;
}