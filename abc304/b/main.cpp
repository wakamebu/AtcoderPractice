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
	if (s.size() <= 3) cout << s << '\n';
	else cout << s.substr(0, 3) << string(s.size() - 3, '0') << '\n';
}