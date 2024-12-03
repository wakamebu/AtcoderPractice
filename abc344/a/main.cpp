#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string n;
  cin >> n;
  int c = n.size();
  int d = -1;
  int e = -1;

  rep(i,c){
    char l = n[i];
    if(l == '|'){
      if(d == -1){
        d = i;
      }else{
        e = i;
        break;
      }
    }
  }

if (d != -1 && e != -1 && e > d) {
        n.erase(d, e - d + 1);  // dからeまでを削除（eも含む）
    }

    cout << n << endl;

  return 0;
}