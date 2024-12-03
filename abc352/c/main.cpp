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
  vector<P> h(n);
  vector<ll> heights(n);
  vector<ll> totals(n);

  rep(i,n){
    int s,k;
    cin>> s >> k;
    h[i] = make_pair(s,k);
  }

 // sort(h.rbegin(),h.rend());
 // sort(h2.rbegin(),h2.rend());

  ll sum = 0;
  rep(i,n){
    sum += h[i].first;
  } 

  rep(i,n){
    sum -= h[i].first;
    heights[i] = sum;
    sum += h[i].first;
    totals[i] = h[i].second + heights[i];
  }

  sort(totals.rbegin(),totals.rend());
  cout << totals.at(0) << endl;
  return 0;
}