#include <bits/stdc++.h>
using namespace std;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = 0; i < (n); ++i)
#define REP2(i, l, r) for (auto i = (l); i < (r); ++i)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long count = 0;

    rep(i, n-2){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') count++;
    }

    while(q--){
        int x;
        char c;
        cin >> x >> c;
        x--; 

        for(int i = x-2; i <= x; ++i){
            if(i >=0 && i <= n-3){
                if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') count--;
            }
        }

        s[x] = c;

        for(int i = x-2; i <= x; ++i){
            if(i >=0 && i <= n-3){
                if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
