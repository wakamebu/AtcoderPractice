#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> extra_edges(M);
    for (int i = 0; i < M; ++i) {
        int X_i, Y_i;
        cin >> X_i >> Y_i;
        extra_edges[i] = {X_i, Y_i};
    }

    vector<long long> dp_prev(N, 0);
    int base_prev = 0; // Initial base index
    dp_prev[(1 - base_prev + N) % N] = 1; // Start from vertex 1

    for (int k = 1; k <= K; ++k) {
        // Process extra edges
        for (int i = 0; i < M; ++i) {
            int u = extra_edges[i].first;
            int v = extra_edges[i].second;
            int idx_u = (u - base_prev + N) % N;
            int idx_v = (v - base_prev + N) % N;
            dp_prev[idx_v] = (dp_prev[idx_v] + dp_prev[idx_u]) % MOD;
        }
        // Increment base index to simulate cyclic shift
        base_prev = (base_prev + 1) % N;
    }

    int idx = (1 - base_prev + N) % N;
    cout << dp_prev[idx] % MOD << endl;
    return 0;
}
