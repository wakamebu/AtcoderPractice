#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

//a~zの分布と、それぞれのアルファベットが登場する数の分布を求める = 2個のmapを使う

int main() {
  string n;
  cin >> n;
  map<char,int> cnt;
  for(char c:n) cnt[c]++;

  map<int,int> cnt2;
  for(auto x : cnt) cnt2[x.second]++;
  for(auto p: cnt2){
    if (p.second != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}