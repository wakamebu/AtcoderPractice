#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for(int i = 0 ; i<N ; i++){
    X.at(i) = i+1;
}

  int A,B;
  cin >> A >>  B;
  int ans = 0;

//各桁の総和
  for(int j = 0 ; j<N ; j++){
    int sum = 0;
    int calc = 0;
    calc += X.at(j) / 10; 
    sum += X.at(j) % 10;

    while(calc != 0){
      sum += calc % 10;
      calc = calc / 10;
    }
      if(sum < (B+1) && sum > (A-1))ans += X.at(j);
    }
  cout << ans << endl;
}