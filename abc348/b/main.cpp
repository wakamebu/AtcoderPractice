#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct N{
  int x;
  int y;
  int index;
};

int main() {
  int n;
  cin >> n;
  vector<N> point(n);

  rep(i,n){
    int one;
    int two;
    cin >> one >> two;
    point[i] = {one,two,i+1};
  }

  rep(i,n){
    int maxdist = 0;
    int ans = 0;
    rep(j,n){
      int dist = (point[i].x - point[j].x) * (point[i].x - point[j].x) +
                 (point[i].y - point[j].y) * (point[i].y - point[j].y);
      if(maxdist<dist){
        maxdist = dist;
        ans = point[j].index;
      }
    }
    cout << ans << endl;
  }
}
