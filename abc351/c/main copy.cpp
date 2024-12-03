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
	vector<int> st;//stack
	rep(i,n){
		int a;
		cin >> a;
		st.push_back(a);
		while(st.size()>1){
			int x = st.back(),y = st.end()[-2];  //st[st.size()-2]でもいい
			if(x != y) break;
			st.pop_back();
			st.pop_back();
			st.push_back(x+1);
		}
	}
	cout << st.size() << endl;
	return 0;
}