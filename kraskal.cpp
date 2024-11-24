#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> parent;
vector<long long> rang;

long long find_set(long long v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(long long a, long long b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b]){
            parent[a] = b;
        } else {
            parent[b] = a;
        }

        if (rang[a] == rang[b]){
            ++rang[a];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    rang.resize(n+1);
    for (long long i = 1; i < n + 1; ++i) {
        parent[i] = i;
        rang[i] = 0;
    }

    vector<pair<long long, pair<long long, long long>>> G;
    for (long long i = 0; i < m; ++i) {
        long long a, b, t;
        cin >> a >> b >> t;
        G.push_back({t, {a, b}});
    }

    sort(G.begin(), G.end());
    vector<bool> visited(n + 1, false);
    long long ans = 0;
    long long cnt = 0;

    for (pair<long long, pair<long long, long long>> j: G) {
        long long a = find_set(j.second.first), b = find_set(j.second.second);
        if (a != b) {
            ans += j.first;
            union_sets(a, b);
            cnt += 1;
            if (cnt == n - 1) {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
