#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> G(10000000);
vector<vector<int>> InverseG(10000000);
vector<bool> visited(10000000, false);
vector<int> TopSort;
vector<int> color(10000000, -1);
set<pair<int, int>> s;

void dfs(int v) {
    visited[v] = true;
    for (int i : InverseG[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    TopSort.push_back(v);
}

void dfs_2(int v, int c) {
    color[v] = c;
    for (int i : G[v]) {
        if (color[i] == -1) {
            dfs_2(i, c);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        InverseG[end].push_back(start);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(TopSort.begin(), TopSort.end());
    int comp = 0;
    for (int i : TopSort) {
        if (color[i] == -1) {
            dfs_2(i, comp++);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j : G[i]) {
            int t = j;
            if (color[i] != color[t]) {
                s.insert(make_pair(min(color[i], color[t]), max(color[i], color[t])));
            }
        }
    }

    cout << comp << ' ' << s.size() << "\n";

    for (const auto &i : s) {
        cout << i.first << ' ' << i.second << "\n";
    }

    // Вывод рёбер между сильно связанными компонентами с минимальными номерами
    set<pair<int, int>> scc_edges;
    for (int i = 1; i <= n; ++i) {
        for (int j : InverseG[i]) {
            if (color[i] != color[j]) {
                scc_edges.insert(make_pair(min(color[i], color[j]), max(color[i], color[j])));
            }
        }
    }

    for (const auto &edge : scc_edges) {
        cout << edge.first << ' ' << edge.second << "\n";
    }

    return 0;
}
