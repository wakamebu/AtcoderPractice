#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int s_len = s.length();
    int t_len = t.length();

    for (int w = 1; w < s_len; w++) {
        for (int c = 1; c <= w; c++) {
            string ans = "";
            for (int i = c - 1; i < s_len; i += w) {
                if (i < s_len) {
                    ans += s[i];
                }
            }
            if (ans == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
