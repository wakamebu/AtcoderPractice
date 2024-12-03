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

  string ans;
  ans = s.substr(3);
  int num = stoi(ans);
  if(0 < num &&num<350 && num != 316){
    cout << "Yes" <<endl;
  }else{
    cout <<"No"<< endl;
  }
  return 0;
}