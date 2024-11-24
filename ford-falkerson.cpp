#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
    int capacity;
    int flow;

    Edge(int _u, int _v, int _capacity) : u(_u), v(_v), capacity(_capacity), flow(0) {}
};

class Graph {
    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> G;
    vector<Edge> edges;

public:
    Graph(int _n) : n(_n), capacity(_n, vector<int>(_n, 0)), G(_n), edges() {}

    void addEdge(int u, int v, int cap) {
        edges.push_back(Edge(u, v, cap));
        edges.push_back(Edge(v, u, 0));
        G[u].push_back(edges.size() - 2);
        G[v].push_back(edges.size() - 1);
        capacity[u][v] += cap;
    }

    int dfs(int s, int t, vector<int> &parent, int min_cap) {
        if (s == t) {
            return min_cap;
        }

        for (int i: G[s]) {
            int next = edges[i].v;
            if (parent[next] == -1 and capacity[s][next] > 0) {
                parent[next] = i;
                int new_flow = min(min_cap, capacity[s][next]);
                int result = dfs(next, t, parent, new_flow);

                if (result > 0) {
                    capacity[s][next] -= result;
                    capacity[next][s] += result;
                    return result;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int max_flow = 0;
        vector<int> parent(n);

        while (true) {
            fill(parent.begin(), parent.end(), -1);
            parent[s] = -2;
            int new_flow = dfs(s, t, parent, 1e9);
            if (new_flow == 0)
                break;
            max_flow += new_flow;
        }

        return max_flow;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if (u == v) {
            continue;
        }
        G.addEdge(u - 1, v - 1, c);
    }

    int max_flow = G.maxFlow(0, n-1);

    cout << max_flow << endl;

    return 0;
}
