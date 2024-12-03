#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,k;
  cin >> n >> a >>b;
  int w = a+b;
  vector<int> plan(n);

  rep(i,n){
  cin >> plan[i];
  plan[i] %= w;
  }

  sort (plan.begin(),plan.end());

  rep(i,n) plan.push_back(plan[i]+w); //2周分

  rep(i,plan.size()-1){
    if(plan[i+1]-plan[i] >= b+1){
      cout << "Yes" << endl;
      return 0;
    }
  }
    cout << "No" << endl;
    return 0;
}