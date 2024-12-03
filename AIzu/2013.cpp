#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	//while(true){
	int n;
	cin >> n;
	//if(n == 0)break;
	vector<int> sum(86401);

	rep(i,n){
		string s, c;
		cin >> s >> c;
		int start = 0, end = 0;
		int a = 0 , b = 0;
		a = stoi(s.substr(0,2));
		b = stoi(c.substr(0,2));
		start += a * 3600;
		end += b * 3600;
		a = stoi(s.substr(3,5));
		b = stoi(c.substr(3,5));
		start += a * 60;
		end += b * 60;
		a= stoi(s.substr(6,8));
		b = stoi(c.substr(6,8));
		start += a;
		end += b;
		sum[start]++;
		sum[end]--;
	}
	
	int res = 0;
	int ans = 1;
	rep(i,86401){
		res += sum[i];
		ans = max(ans,res);
	}
	cout << ans << endl;

	//}
	return 0;
}