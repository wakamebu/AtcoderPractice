#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;
        
        vector<vector<int>> grid(h, vector<int>(w));
        vector<vector<int>> sidewall(h, vector<int>(w - 1));
        vector<vector<int>> verticalwall(h - 1, vector<int>(w));

        for (int i = 0; i < 2 * h - 1; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < w - 1; j++) {
                    cin >> sidewall[i / 2][j];
                }
            } else {
                for (int j = 0; j < w; j++) {
                    cin >> verticalwall[i / 2][j];
                }
            }
        }

        vector<P> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        P start = {0, 0};

        queue<P> q;
        vector<vector<int>> dist(h, vector<int>(w, -1));
        q.push(start);
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int x = a + dx;
                int y = b + dy;
                if (x < 0 || y < 0 || x >= h || y >= w) continue;
                if (dist[x][y] != -1) continue;
                if (dx == 0 && dy == 1 && sidewall[a][b] == 1) continue; // 右側の壁
                if (dx == 1 && dy == 0 && verticalwall[a][b] == 1) continue; // 下側の壁
                if (dx == 0 && dy == -1 && sidewall[a][b - 1] == 1) continue; // 左側の壁
                if (dx == -1 && dy == 0 && verticalwall[a - 1][b] == 1) continue; // 上側の壁
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
            }
        }

        if (dist[h - 1][w - 1] == -1) {
            cout << 0 << endl;
        } else {
            cout << dist[h - 1][w - 1] << endl;
        }
    }
}
