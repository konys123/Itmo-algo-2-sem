#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G(1000000);


bool dfs(int v,vector<bool>& grey, int x) {
    grey[v] = true;
    for (int i: G[v]) {
        if (i == x){
            return 1;
        }
        if (!grey[i] and dfs(i,grey,x)) {
            return 1;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "YES" << '\n';
            continue;
        }
        vector<bool> visit_1(n + 1, 0);
        vector<bool> visit_2(n + 1, 0);
        if (dfs(a, visit_1, b) and dfs(b, visit_2, a)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;

}
