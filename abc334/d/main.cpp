#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,q;
  cin >> n >> q;
  deque<ll> R;
  ll o;
  rep(i,n){
    cin >> o;
    R.push_back(o);
  }
  sort(R.begin(),R.end());

  vector<ll> qu(q);
  vector<ll> s(q);
  rep(i,q) cin >> qu[i];
  s = qu;
  map<ll,ll> t;
  rep(i,q) t[qu[i]] = 0;
  sort(qu.begin(),qu.end());

  ll ms = 0;
  ll mx = 0;
  ll it = 0;

  rep(i,q){
    ll x = qu[i] - ms;
    while(!R.empty() && x>=R.front()){
        it++;
        ms += R.front();
        mx = R.front();
        R.pop_front();
        x -= mx;
    }
    t[qu[i]] = it;
  }


  rep(i,q){
    cout << t[s[i]] << endl;
  }

  return 0;
}