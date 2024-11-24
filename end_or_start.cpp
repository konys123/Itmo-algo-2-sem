#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

bool dfs(int v, int v1) {
    visited[v] = true;
    for (int i: G[v]) {
        if (i == v1) {
            return true;
        }
        if (!visited[i]) {
            if (dfs(i, v1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    G.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }


    for (int i = 0; i < q; ++i) {
        char request;
        int A, B;
        cin >> request >> A >> B;

        if (request == '?') {
            if (A == B) {
                cout << "YES" << '\n';
                continue;
            }
            visited.assign(n + 1, false);
            if (dfs(A, B)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else if (request == '-') {
            erase(G[A], B);
            erase(G[B], A);
        }
    }

    return 0;
}
