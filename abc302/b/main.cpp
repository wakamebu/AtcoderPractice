#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}

int main() {
	int n,m,x,y;
	int dx[8]={-1,-1,-1,0,0,1,1,1};
	int dy[8]={-1,0,1,-1,1,-1,0,1};
	string str;
	cin>>n>>m;
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<8;k++){
				str="";
				for(int t=0;t<5;t++){
					x=i+t*dx[k],y=j+t*dy[k];
					if((x<0)||(x>=n)||(y<0)||(y>=m))break;
					str+=s[x][y];
				}
              	if(str=="snuke"){
					for(int t=0;t<5;t++){
						x=i+t*dx[k]+1,y=j+t*dy[k]+1;
						cout<<x<<" "<<y<<endl;
					}
					return 0;
				}
			}
		}
	}
	return 0;
}