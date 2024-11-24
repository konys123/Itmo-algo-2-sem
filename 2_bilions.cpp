#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> rang;

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
        }

        if (rang[a] == rang[b]) {
            ++rang[a];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    rang.resize(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        parent[i] = i;
        rang[i] = 0;
    }

    vector<pair<int, pair<int, int>>> G;
    vector<pair<int, pair<int, int>>> mst;
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        G.push_back({t, {a, b}});
    }

    sort(G.begin(), G.end());
    vector<bool> visited(n + 1, false);
    int ans = 0;
    int cnt = 0;

    for (pair<int, pair<int, int>> j: G) {
        int a = find_set(j.second.first), b = find_set(j.second.second);
        if (a != b) {
            mst.push_back(j);
            ans += j.first;
            union_sets(a, b);
            cnt += 1;
            if (cnt == n - 1) {
                break;
            }
        }
    }

    cout << ans << ' ';

    int ans_1 = 1e9;

    for (pair<int, pair<int, int>> i: mst) {
        for (int i = 1; i < n + 1; ++i) {
            parent[i] = i;
            rang[i] = 0;
        }
        ans = 0;
        cnt = 0;
        for (pair<int, pair<int, int>> j: G) {
            if (i != j) {
                int a = find_set(j.second.first), b = find_set(j.second.second);
                if (a != b) {
                    ans += j.first;
                    union_sets(a, b);
                    cnt += 1;
                    if (cnt == n - 1) {
                        break;
                    }
                }
            }
        }
        ans_1 = min(ans_1, ans);
    }

    cout << ans_1;

    return 0;
}
