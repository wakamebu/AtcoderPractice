#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	int n,m;
	while(cin >> n >> m ,n && m){
	vector<int> cb(m);
	rep(i,m)cin >> cb[i];
	vector<int> comp(n);
	rep(i,n)cin >> comp[i];

	int data = 128;
	//i番目までのデータがjのとき、作ることができる最小の二乗和
	vector<vector<int>> dp(n+1,vector<int>(256,1e9));
	dp[0][128] = 0;

	for(int i = 0;i<n;i++){
		for(int j = 0;j<256;j++){
			if(dp[i][j] == 1e9)continue;
			for(int k = 0;k<m;k++){
				int nj = j + cb[k];
				if(nj > 255) nj = 255;
				if(nj < 0) nj = 0;
				int tmp = (nj-comp[i])*(nj-comp[i]);
				if(dp[i][j]+tmp < dp[i+1][nj]){
					dp[i+1][nj] = dp[i][j] + tmp;
				}
			}
		}
	}
	int ans = 1e9;
	for(int i = 0;i<256 ;i++){
		ans = min(ans,dp[n][i]);
	}
	cout << ans << endl;
	}
}