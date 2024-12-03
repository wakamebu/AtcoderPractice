#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#include <stdlib.h>

int main() {
  int n;
  cin >> n;

  vector<tuple<int,int,int>> travel;
  travel.push_back(make_tuple(0,0,0));

  //配列を制作
  for(int i = 1; i<n+1 ; i++){
    int t,x,y;
    cin >> t >> x >> y;
    travel.push_back(make_tuple(t,x,y));
  }

  //存在できる？
  bool can = true;
  for(int i = 0; i<n ; i++){
    int t,x,y;
    int t2,x2,y2;
    tie(t,x,y) = travel.at(i);
    tie(t2,x2,y2) = travel.at(i+1);
    int dt = abs(t2 - t);
    int dist = abs(x2-x) + abs(y2 - y);
    if(dist>dt) can = false;
    if(dist % 2 != dt % 2) can = false;
  }

  if(can == true){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}