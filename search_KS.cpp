#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G(100000);
vector<bool> grey(100000, 0);
int ans = 0;

void dfs(int v){
    grey[v] = true;
    for (int i:G[v]) {
        if (!grey[i]){
            dfs(i);
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k, j;
        cin >> k >> j;
        G[k].push_back(j);
        G[j].push_back(k);
    }

    for (int i = 1; i < n+1; ++i) {
        if (!grey[i]) {
            ans += 1;
            dfs(i);
        }
    }

    cout << ans;

    return 0;
}
