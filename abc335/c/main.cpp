#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
  int n,q;
  cin >> n >> q;

  deque<P> gr;

  int x = 1;
  int y = 0;

  rep(i,n+1){
    if(i == 0 )continue;
    gr.push_back(make_pair(i,0));
  }

  int it = 0;
  rep(i,q){
    int p = 0;
    cin >> p ;
    if(p == 1){
      it++;
      char c;
      cin >> c;
      if(c == 'R'){
        x++;
        gr.push_front(make_pair(x,y));
        gr.pop_back();
      }
      if(c == 'L'){
        x--;
        gr.push_front(make_pair(x,y));
        gr.pop_back();
      }
      if(c == 'U'){
        y++;
        gr.push_front(make_pair(x,y));
        gr.pop_back();
      }
      if(c == 'D'){
        y--;
        gr.push_front(make_pair(x,y));
        gr.pop_back();
      }
    }

    if(p == 2){
      int q;
      cin >> q;
      if(it == 0)cout << q << " " << 0 << endl;
      if(it > 0){
        q--;
        cout << gr[q].first << " " << gr[q].second << endl;
        continue;
      }
    }

  }

  return 0;
}