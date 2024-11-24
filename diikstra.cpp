#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void deikstra(vector<vector<pair<int, int>>> &G, vector<int> &dist) {
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (pair<int, int> neighbor: G[u]) {
            int v = neighbor.second;
            int w = neighbor.first;

            if (dist[u] + w < dist[v] or dist[v] == -1) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        G[a].push_back({t, b});
    }


    vector<int> dist(n+1,-1);
    dist[1] = 0;
    deikstra(G, dist);

    cout << dist[n];

    return 0;
}
