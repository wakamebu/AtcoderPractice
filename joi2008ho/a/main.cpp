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


int main()
{
    int N;
    cin >> N;
    vector<bool> stones(N);
    rep(i, N)
    {
        int x;
        cin >> x;
        stones[i] = (x == 1);
    }

    deque<pair<bool, int>> deq;

    rep(i, N)
    {
        if (i == 0)
        {
            deq.push_back(make_pair(stones[i], 1));
        }
        else if (i % 2 == 0)
        {
            auto [c, len] = deq.back();
            if (c == stones[i])
            {
                deq.pop_back();
                deq.push_back(make_pair(c, len + 1));
            }
            else
                deq.push_back(make_pair(stones[i], 1));
        }
        else
        {
            auto [c, len] = deq.back();
            deq.pop_back();
            if (c == stones[i])
            {
                // cout << c << ", " << len + 1 << endl;
                deq.push_back(make_pair(c, len + 1));
            }
            else
            {
                // cout << !c << ", " << len + 1 << endl;
                if (deq.size() == 0)
                    deq.push_back(make_pair(!c, len + 1));
                else
                {
                    auto [p, q] = deq.back();
                    if (p == !c)
                    {
                        deq.pop_back();
                        deq.push_back(make_pair(p, q + len + 1));
                    }
                    else
                    {
                        deq.push_back(make_pair(!c, len + 1));
                    }
                }
            }
        }
    }

    long long answer = 0;
    while (deq.size())
    {
        auto [c, len] = deq.front();
        deq.pop_front();
        if (c == false)
            answer += len;
    }
    cout << answer << endl;

    return 0;
}