#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
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

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int queryMin(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryMin(2 * node + 1, start, mid, l, r);
        int rightMin = queryMin(2 * node + 2, mid + 1, end, l, r);
        return min(leftMin, rightMin);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int queryMin(int l, int r) {
        return queryMin(0, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};

// 任意の点で区切って前後をソートするための最小回数を求める関数
int minOperations(vector<int>& P) {
    int n = P.size();
    SegmentTree segTree(P);

    // 前半部分と後半部分の最小ソート回数を管理
    vector<int> minOpsLeft(n, 0), minOpsRight(n, 0);
    
    for (int i = 0; i < n; ++i) {
        int minIndex = -1;
        for (int j = i; j < n; ++j) {
            if (P[j] == i + 1) {
                minIndex = j;
                break;
            }
        }
        if (minIndex == -1) continue;

        if (minIndex != i) {
            sort(P.begin() + i, P.begin() + minIndex + 1);
            minOpsLeft[i] = 1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int minIndex = -1;
        for (int j = i; j >= 0; --j) {
            if (P[j] == n - i) {
                minIndex = j;
                break;
            }
        }
        if (minIndex == -1) continue;

        if (minIndex != i) {
            sort(P.begin() + minIndex, P.end());
            minOpsRight[i] = 1;
        }
    }

    int minOperations = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        minOperations = min(minOperations, minOpsLeft[i] + minOpsRight[i + 1]);
    }

    return minOperations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        cout << minOperations(p) << endl;
    }
    return 0;
}