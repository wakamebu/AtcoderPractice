#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> tests(m);
  vector<int> t(m);

  for(int i = 0; i < m ; i++){
    int C;
    cin >> C;
    tests[i].resize(C);
    for(int j = 0; j<C; j++){
      int A;
      cin >> A;
      tests[i][A-1] = 1;
    }
    string S;
    cin >> S;
    if(S == "o")t.at(i) = 1;
    else t.at(i) = 0;
  }

  int res = 0;

  
  for(int i = 0; i< (1<<n) ; i++){
    vector<int> tf(n);
    for(int j = 0; j <n ; j++){
    if(i & (1<<j)){tf[j]=1;}
    else{tf[j]=0;}
    }

    
   bool jud=true;
    for(int j=0;j<m;j++){
      int ck=0;
      for(int p=0;p<n;p++){
        if(tests[j][p]==1 && tf[p]==1){ck++;}
      }
      if(ck>=k && t[j]==0){jud=false;}
      if(ck<k && t[j]==1){jud=false;}
    }
    if(jud){res++;}
  }
  cout << res << "\n";
  return 0;
}