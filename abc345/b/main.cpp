#include <iostream>
using namespace std;
int main() {
  long long X;
  cin >> X;
  if ((X + 9) < 0 and (X + 9) % 10 != 0) {
    cout << (X + 9) / 10 - 1 << endl;
  } else {
    cout << (X + 9) / 10 << endl;
  }
}