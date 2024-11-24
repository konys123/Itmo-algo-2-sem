#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void deikstra(vector<vector<pair<int, int>>> &G, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        v.resize(0);
        for (int j = 0; j < s; ++j) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int j = 0; j <= v.size() - 2; ++j) {
            for (int l = j + 1; l <= v.size() - 1; ++l) {
                G[v[j]].push_back({t, v[l]});
                G[v[l]].push_back({t, v[j]});
            }
        }
    }

    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    deikstra(G, dist);
    cout << dist[k];


    return 0;
}
