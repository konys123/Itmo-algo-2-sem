#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G(100000);
vector<bool> grey(100000, 0);
vector<int> TopSort;


void dfs(int v){
    grey[v] = true;
    for (int i:G[v]) {
        if (!grey[i]){
            dfs(i);
        }
    }
    TopSort.push_back(v);
}


int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k, j;
        cin >> k >> j;
        G[k].push_back(j);
    }

    for (int i = 1; i < n+1; ++i) {
        if (!grey[i]) {
            dfs(i);
        }
    }

    vector<int> ans(n + 1);
    int k = n;
    for (int i = 0; i < n; ++i) {
        ans[TopSort[i]] = k;
        k--;
    }

    for (int i = 1; i < n + 1; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
