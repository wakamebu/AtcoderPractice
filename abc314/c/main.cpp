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

  string s;
  cin >> s;

  string t = "";
  map<int,deque<char>> c;
  vector<int> pos(n);

  rep(i,n)cin >> pos[i];

  rep(i,n){
    int a = pos[i];
    c[a].push_back(s[i]);
  }  

  for(auto &e :c){
    if(e.second.size() > 0){
    char l = e.second.back();
    e.second.pop_back();
    e.second.push_front(l);
    }
  }

  rep(i,n){
    int b = pos[i];
    t += c[b].front();
    c[b].pop_front();
  }

  cout << t << endl;
  return 0;
}