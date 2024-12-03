#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string S;
  cin >> S;
  char C;

  int siz = S.size();
  int cnt = 0;
  rep(i,siz){
    C = S[i];
    if('A' <= C && C <='Z'){
      cnt++;
    }
  }

  if(cnt > siz - cnt){
    transform(S.begin(),S.end(),S.begin(),::toupper);
  }else{
    transform(S.begin(),S.end(),S.begin(),::tolower);
  }
    cout << S << endl;
  return 0;
}