#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, M, answer = 0;
  cin >> N >> M;
  vector<int64_t> A(N);
  vector<int64_t> B(M);
  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int64_t i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  sort(B.begin(), B.end());
  for (int64_t i = 0; i < M; i++) {
    if(A.size() == 0){
      answer = -1;
      break;
    }
    for (int64_t j = A.size()-1; j > -1; j--) {
      if(B.at(i)<=A.at(j)){
      answer += A.at(j);
      A.pop_back();
      break;
      }
      else if(j == 0){answer = -1;}
      A.pop_back();
    }
    if(answer == -1) break;
  }
  cout << answer << endl;
  return 0;
} 