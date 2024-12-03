#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;
    
    vector<pair<int,int>> p;
    for (int x = 0; x<N; x++){ p.emplace_back(A[x],0);}
    for (int x = 0; x<M; x++){ p.emplace_back(B[x],1);}
    sort(p.begin(), p.end());
    set<int> st(A.begin(), A.end());
    for (int i = 0; i < N + M - 1; ++i) {
        if (p[i].second == (0) && (p[i+1].second) == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}