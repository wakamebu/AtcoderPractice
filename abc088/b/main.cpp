#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int A;
  vector<int> card(n);
  for(int i = 0; i<n ; i++){
    cin >> A;
    card.at(i) = A;
  }

  sort(card.begin(),card.end(),greater<int>());
  int sumA =0;
  int sumB =0;

  for(int j = 0; j<n ; j++){
    if(j%2 ==0){
    sumA += card[j];
    }else{
    sumB += card[j];
    }
  }

  cout << max(sumA,sumB) - min(sumA,sumB) << endl;
  return 0;
}
