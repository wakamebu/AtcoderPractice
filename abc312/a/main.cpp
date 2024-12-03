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
	string t = "ACEGBDFAC";
	cout << (t.find(s) == string::npos ? "No" : "Yes") << '\n';
}