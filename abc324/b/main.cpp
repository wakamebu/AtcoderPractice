#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    ll N;
    cin >> N;
    
    while (N % 3 == 0)
        N /= 3;
    while (N % 2 == 0)
        N /= 2;
    
    if (N == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}