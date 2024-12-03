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
  string s;
  cin >> s;
  int q;
  cin >> q;

  vector<pair<char,char>> change(q);
  rep(i,q){
    char c,d;
    cin >> c >> d;
    change[i] = make_pair(c,d);
  }

  vector<pair<char,char>> final(26);
  char e = 'a';
  rep(i,26){
    final[i] = make_pair(e,e);
    e++;
  }
  
  rep(i,change.size()){
    char c = change[i].first;
    rep(j,26){
      if(final[j].first == c){
        final[j].first = change[i].second;
        continue;
      }
    }
  }

  rep(i,n){
    char c = s[i];
    rep(j,26){
      if(final[j].second == c){
        c = final[j].first;
        cout << c;
        break;
      }
    }
  }

  cout << endl;
  return 0;
}