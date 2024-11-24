#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> G;



void dfs(int v,int * parent) {
    for (int i: G[v]) {
        if (i != parent[v]) {
            parent[i] = v;
            dfs(i,parent);
        }
    }
}

vector<int> code_prufera(int n){
    int parent[n];
    int deg[n];
    parent[n-1] = -1;
    dfs(n-1,parent);
    int ptr = -1;
    for (int i = 0; i < n; ++i) {
        deg[i] = G[i].size();
        if (deg[i] == 1 and ptr == -1){
            ptr = i;
        }
    }

    vector<int> code;
    int leaf = ptr;
    for (int i = 0; i < n-2; ++i) {
        int next = parent[leaf];
        code.push_back(next);
        --deg[next];
        if (deg[next] == 1 and next < ptr){
            leaf = next;
        }
        else{
            ++ptr;
            while (ptr<n and deg[ptr] != 1){
                ++ptr;
            }
            leaf = ptr;
        }
    }
    return code;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    G.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        G[start].push_back(end);
        G[end].push_back(start);
    }

    vector<bool> leafs(n + 1, false);

    for (int i = 1; i < n + 1; ++i) {
        if (G[i].size() == 1) {
            leafs[i] = true;
        }
    }

    vector<int> kod = code_prufera(n);

    for (int i = 0; i < n-2; ++i) {
        cout << ++kod[i] << ' ';
    }

    return 0;
}
