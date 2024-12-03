#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Sheet{
  int h,w;
  set<P> s;
  void input() {
    cin >> h >> w;
    rep(i,h) {
      string str;
      cin >> str;
      rep(j,w)if(str[j] == '#') s.emplace(i,j);
    }
  }
  void shift(int di , int dj) {
    set<P> old;
    swap(s,old);
    for(auto [i,j]:old)s.emplace(i+di,j+dj);
  }
  bool copy(Sheet a, int di ,int dj){
    a.shift(di,dj);
    s.merge(a.s);
    return true;
  }
  void normalize(){
    int li = 1e9, lj = 1e9;
    for(auto[i,j] :s){
      li = min (li,i);
      lj = min (lj,j);
    }
    shift(-li,-lj);
  }
};

int main() {
  Sheet a,b,x;

  a.input();
  b.input();
  x.input();
  x.normalize();


      for(int bi = -10; bi < 10; bi++){
        for(int bj = -10; bj < 10; bj++){
          Sheet y = a;
          y.copy(b,bi,bj);
          y.normalize();  
          if(x.s == y.s){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    
  



  cout << "No" << endl;
  return 0;
}