#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    vector<vector<vector<int>>> arr(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));
    vector<vector<vector<int>>> d = arr;

    while (cin) {
        int a, b, c, j;
        cin >> a >> b >> c >> j;
        if (a <= x and b <= y and c <= z) {
            arr[a][b][c] = j;
        }
    }

    d[1][1][1] = arr[1][1][1];

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 1; k <= z; ++k) {
                d[i][j][k] = arr[i][j][k] + max({d[i - 1][j][k], d[i][j - 1][k], d[i][j][k - 1]});
            }
        }
    }

    cout << d[x][y][z];

    return 0;
}