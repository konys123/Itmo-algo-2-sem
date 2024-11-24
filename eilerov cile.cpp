#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<long long> ans;
vector<vector<long long>> G;

void Euler_cicle(long long v) {
    while (!G[v].empty()) {
        long long u = *G[v].begin();
        erase(G[v],u);
        erase(G[u],v);
        Euler_cicle(u);
    }
    ans.push_back(v);
}

int main() {
    long long n, m;
    cin >> n >> m;
    G.resize(n + 1);

    for (long long i = 0; i < m; ++i) {
        long long start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }

    for (long long i = 1; i <= n; ++i) {
        if (G[i].size() % 2 != 0) {
            cout << ":(";
            return 0;
        }
    }

    Euler_cicle(1);

    if (ans.size() >= m + 1) {
        for (int i = ans.size()-1; i >= 0; --i) {
            cout << ans[i] << ' ';
        }
    }
    else {
        cout << ":(";
    }
    return 0;
}
