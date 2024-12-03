#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> win(n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		win[i] = {count(s.begin(), s.end(), 'o'), -i};
	}
	sort(win.rbegin(), win.rend());
	vector<int> ans(n);
	for(int i = 0; i < n; i++) ans[i] = -win[i].second + 1;
	for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}