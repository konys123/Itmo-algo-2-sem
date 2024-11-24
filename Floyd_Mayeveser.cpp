#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long min_sum = 1e19, ans;

    vector<vector<unsigned long long>> dist(n + 1, vector<unsigned long long>(n + 1, 1e19));

    for (int i = 1; i < n + 1; ++i) {
        dist[i][i] = 0;
    }

    for (unsigned long long i = 0; i < m; ++i) {
        unsigned long long a, b, t;
        cin >> a >> b >> t;
        dist[a][b] = min(dist[a][b], t);
        dist[b][a] = min(dist[b][a], t);
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int a = 1; a < n + 1; ++a) {
            for (int b = 1; b < n + 1; ++b) {
                if (dist[a][i] != 1e19 and dist[i][b] != 1e19 and dist[a][b] > dist[a][i] + dist[i][b]) {
                    dist[a][b] = dist[a][i] + dist[i][b];
                }
            }
        }
    }


    for (int i = 1; i < n + 1; ++i) {
        unsigned long long current_sum = 0;
        for (int j = 1; j < n + 1; ++j) {
            current_sum += dist[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            ans = i;
        }
    }

    cout << ans;


    return 0;
}
