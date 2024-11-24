#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void deikstra(vector<vector<pair<unsigned long long, unsigned long long>>> &G, vector<unsigned long long> &dist,
              unsigned long long start) {
    priority_queue<pair<unsigned long long, unsigned long long>, vector<pair<unsigned long long, unsigned long long >>, greater<pair<unsigned long long, unsigned long long>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        unsigned long long u = pq.top().second;
        unsigned long long d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (pair<unsigned long long, unsigned long long> neighbor: G[u]) {
            unsigned long long v = neighbor.second;
            unsigned long long w = neighbor.first;

            if (dist[u] + w < dist[v] or dist[v] == 1e20) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long min_sum = 1e20, ans;

    vector<vector<pair<unsigned long long, unsigned long long>>> G(n + 1);
    for (unsigned long long i = 0; i < m; ++i) {
        unsigned long long a, b, t;
        cin >> a >> b >> t;
        G[a].push_back({t, b});
        G[b].push_back({t, a});
    }

    for (unsigned long long i = 1; i <= n; ++i) {
        vector<unsigned long long> dist(n + 1, 1e20);
        dist[i] = 0;
        deikstra(G, dist, i);
        unsigned long long sum = 0;
        for (unsigned long long j = 1; j <= n; ++j) {
            sum += dist[j];
        }
        if (sum < min_sum) {
            ans = i;
            min_sum = sum;
        }
    }
    cout << ans;

    return 0;
}
