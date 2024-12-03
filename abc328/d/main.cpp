#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    
    vector<char> ss;
    for (char ch : s) {
        ss.push_back(ch);
    }

    int n = ss.size();
    vector<char> result;

    for (int i = 0; i < n; ++i) {
        int m = result.size();
        if (m >= 2 && result[m - 2] == 'A' && result[m - 1] == 'B' && ss[i] == 'C') {
            result.pop_back(); // Remove B
            result.pop_back(); // Remove A
        } else {
            result.push_back(ss[i]);
        }
    }

    for (char ch : result) {
        cout << ch;
    }
    cout << endl;

    return 0;
}