#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(1000000);
    for (int i = 0; i < 1000000; ++i) {
        parent[i] = i;
    }
    int minimum = n;
    vector<pair<int, pair<int, int>>> G;
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;

        G.push_back({t*-1, {a, b}});
        minimum = min(minimum,a);
        minimum = min(minimum,b);
    }
    minimum = abs(minimum);
    for (pair<int, pair<int, int>> j: G) {
        j.second.first += minimum;
        j.second.second += minimum;
    }

    sort(G.begin(), G.end());

    int ans = 0;
    int cnt = 0;
    for (pair<int, pair<int, int>> j: G) {
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

    cout << ans*-1;

    return 0;
}
