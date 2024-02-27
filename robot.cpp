#include <iostream>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int pole[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pole[i][j];
        }
    }

    long long int d_1[n][m];
    long long int d_2[n][m];

    d_1[0][0] = pole[0][0];
    for (int j = 1; j < m; ++j) {
        d_1[0][j] = d_1[0][j - 1] + pole[0][j];
    }
    for (int j = 1; j < n; ++j) {
        d_1[j][0] = d_1[j - 1][0] + pole[j][0];
    }
    for (int j = 1; j < n; ++j) {
        for (int k = 1; k < m; ++k) {
            d_1[j][k] = max(d_1[j - 1][k], d_1[j][k - 1]) + pole[j][k];
        }
    }


    d_2[n - 1][m - 1] = pole[n - 1][m - 1];
    for (int j = m - 2; j >= 0; --j) {
        d_2[n - 1][j] = d_2[n - 1][j + 1] + pole[n - 1][j];
    }
    for (int j = n - 2; j >= 0; --j) {
        d_2[j][m - 1] = d_2[j + 1][m - 1] + pole[j][m - 1];
    }
    for (int j = n - 2; j >= 0; --j) {
        for (int k = m - 2; k >= 0; --k) {
            d_2[j][k] = max(d_2[j + 1][k], d_2[j][k + 1]) + pole[j][k];
        }
    }


    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        long long ans;

        ans = d_1[x][y] + d_2[x][y] - pole[x][y];

        cout << ans << '\n';
    }

    return 0;
}
