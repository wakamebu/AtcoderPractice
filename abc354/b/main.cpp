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

  map<string,int> ACj;
  rep(i,n){
    string S;
    int rate;
    cin >> S >> rate;
    ACj[S] = rate;
  }

  int  sum =  0;
  vector<string> player;
  for(pair<string,int> p : ACj){
    string key = p.first;
    auto value = p.second;
    //cout << key << endl;
    sum += value;
    player.emplace_back(key);
  }
  //cout << sum << endl;
  int ans = sum % n;
  //cout << ans << endl;

  //sort (player.begin(),player.end()); //ループの時点でkeyが小さい順に追加されていくからsortしなくてもいい。逆順に並び替える時はgood

  cout << player.at(ans) << endl;
  return 0;
}