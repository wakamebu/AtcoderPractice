#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,y;
  cin >> n >> y;
  int res10000 = -1, res5000 = -1, res1000 = -1;

  for(int i = 0; i<n+1; i++){
    for(int j = 0; i + j<n+1; j++){
      int c = n - i - j;
      int total = 10000*i + 5000*j + 1000*c;
        if(total == y){
                res10000 = i;
                res5000 = j;
                res1000 = c;
      }
    }
  }
    cout << res10000 << " " << res5000 << " " << res1000 << endl;
  
  return 0;
}