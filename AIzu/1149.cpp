#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

const int MAX_N = 1000001;
const int INF = 1e+8;

struct piece {
    int id; // 識別番号
    int w;
    int d;

    int area() const {
        return w * d;
    }
};

bool compare_pieces(const piece& a, const piece& b) {
    if (a.id != b.id)
        return a.id < b.id;
    return a.area() < b.area();
}

int main() {
    //魔除けの呪文
    ios::sync_with_stdio(false);
    cin.tie(0);

        while(true){
        int n,w,d;
        cin >> n >> w >> d;
        if(n == 0)return 0;

        vector<piece> cake;
        cake.push_back(piece{1, w, d});
        int next_id = 2;

        auto cut = [&](int wi,int di,int s){
            int where = 0;
            if(s > wi + di + wi){
                s -= wi - di - wi;
                where = 3;
            }else if(s > wi + di){
                s -= wi - di;
                where = 2;
            }else if(s >wi){
                s -= wi;
                where = 1;
            }else{
                where = 0;
            }
            pair<int,int> answer = {s,where};
            return answer;
        };

        while(n--){
            int p , s;
            cin >> p >> s;
            p--;

            auto it = find_if(cake.begin(), cake.end(), [&](const piece& pc) { return pc.id == p + 1; });
            piece original = *it;

            piece &current = cake[p];
            int wi = current.w;
            int di = current.d;

            //start = どこから、どの面から切るか
            pair<int,int> start;
            start = cut(wi,di,s);

            //切ったあとのピースは２つに増える
            cake.erase(it);
            piece piece1; // left
            piece piece2; // right

            if(start.second %2 == 0){
                //高さは変わらない
                int new_wi_1 = wi - start.first;
                int new_wi_2 = start.first;
                piece1 = {next_id++,new_wi_1,di};
                piece2 = {next_id++,new_wi_2,di};
            }else{
                int new_di_1 = di - start.first;
                int new_di_2 = start.first;
                piece1 = {next_id++,wi,new_di_1};
                piece2 = {next_id++,wi,new_di_2};
            }
            if(piece1.area() > piece2.area()) swap(piece1, piece2);

            cake.push_back(piece1);
            cake.push_back(piece2);
        }
        sort(cake.begin(), cake.end(), [&](const piece& a, const piece& b) -> bool {
                if(a.area() != b.area())
                    return a.area() < b.area();
                return a.id < b.id;
            });
        for(auto&piece : cake){
            cout << piece.area() << endl;
        }
        }

}
