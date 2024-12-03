#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;

  //後ろから解くために左右反転する
  reverse(S.begin(), S.end());
  string divide[4] = {"dream", "dreamer", "erase", "eraser"};
  for (int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());//vectorならdivide.at(i)

   bool can = true;

  for (int i = 0; i < S.size();) {
        bool can2 = false; // 4 個の文字列たちどれかで divide できるか
        for (int j = 0; j < 4; ++j) {
            string d = divide[j];
            if (S.substr(i, d.size()) == d) { // d で divide できるか
                can2 = true;
                i += d.size(); // divide できたら i を進める
            }
        }
        if (!can2) { // divide できなかったら
            can = false;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}