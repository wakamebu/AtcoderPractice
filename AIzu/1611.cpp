#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	while(true){
	int n;
	cin >> n;
	if(n == 0)break;
	vector<int> w(n);
	rep(i,n)cin >> w[i];

	//dp[l][r]の区間が残っている中で、取り除くことができるブロックの最大個数
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	dp[0][0] = 0;
	rep(l,n-1){
		int r = l+1;
		if(abs(w[r] - w[l]) <= 1)dp[l][l+2] = 2;
	}

	for(int len = 3;len<=n;len++){
		for(int l = 0;l + len <= n ; l++){
			int r = l + len;
			for(int k = l+1; k < r;k++){
				dp[l][r] = max(dp[l][r],dp[l][k] + dp[k][r]);
			}
				if(dp[l+1][r-1] == len -2 and abs(w[l] - w[r-1]) <= 1){
					dp[l][r] = max(dp[l][r],len);
				}
			}
		}

	cout << dp[0][n] << endl;
	}
	return 0;
}