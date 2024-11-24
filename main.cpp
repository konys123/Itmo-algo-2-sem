#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G(1000000);
bool foundCycle = false;

void dfs(int v, int count, vector<bool> &visited, int start) {
    visited[v] = true;
    count += 1;
    for (int i: G[v]) {
        if (i == start and count > 2 and !foundCycle) {
            foundCycle = true;
            cout << "YES";
            return;
        }
        if (!visited[i]) {
            dfs(i, count, visited, start);
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
        G[end].push_back(start);
    }

    for (int i = 1; i < n + 1; ++i) {
        if (!foundCycle) {
            vector<bool> visited(n + 1, false);
            dfs(i, 0, visited, i);
        } else {
            break;
        }
    }
    if (!foundCycle) {
        cout << "NO";
    }

    return 0;
}
