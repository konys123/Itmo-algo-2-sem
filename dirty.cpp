#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>> G;
vector<bool> visited;
int timee = 0, color = 0;
stack<int> st;
vector<int> tin;
vector<int> up;
vector<int> colors;

void paint(int v) {
    ++color;
    int last = -1;
    while (last != v and !st.empty()) {
        colors[st.top()] = color;
        last = st.top();
        st.pop();
    }
}

void dfs(int v, int parent) {
    visited[v] = true;
    ++timee;
    st.push(v);
    tin[v] = timee;
    up[v] = timee;
    for (int u: G[v]) {
        if (!visited[u]) {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > tin[v]) {
                paint(u);
            }
        } else if (u != parent) {
            up[v] = min(up[v], tin[u]);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    G.resize(n + 1);
    tin.resize(n + 1);
    up.resize(n + 1);
    colors.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }
    for (int i = 0; i < n + 1; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (colors[a] == colors[b]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
