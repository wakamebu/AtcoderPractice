//DFS template
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main() {
    // 頂点数と辺数
    int n;
    cin >> n;
    Graph G(n);
    for(int i = 0; i < (n); i++){
        int from,vertex;
        cin >> from >> vertex;
        from--;
        for(int j = 0; j < vertex; j++){
            int to;
            cin >> to;
            to--;
            G[from].emplace_back(to);
        }
    }

    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nv : G[v]){
            if(dist[nv] != -1)continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    for(int v = 0;v<n;v++) cout << v+1 << " " << dist[v] <<endl;
    return 0;
}