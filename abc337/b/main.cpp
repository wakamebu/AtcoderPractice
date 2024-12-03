#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    string S;
    cin >> S;
    string t = S;
    //正規表現ver
    //regex re("A*B*C*");
    //if (regex_match(s,re)) cout << "Yes" << endl;
    sort(t.begin(),t.end());
    if(S == t)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}