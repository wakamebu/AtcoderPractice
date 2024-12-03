#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  map<string,int> god;
  string s;
  cin >> s;

  god["tourist"] = 3858;
  god["ksun48"] = 3679;
  god["Benq"] = 3658;
  god["Um_nik"] = 3648;
  god["apiad"] = 3638;
  god["Stonefeang"] = 3630;
  god["ecnerwala"] = 3613;
  god["mnbvmar"] = 3555;
  god["newbiedmy"] = 3516;
  god["semiexp"] = 3481;

  cout << god[s] << endl;
  return 0;

}