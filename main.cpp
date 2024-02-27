#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void make_grey_code(vector<vector<bool>>& grayCode, int n, int& row) {
    if (n == 0) {
        return;
    }

    make_grey_code(grayCode, n - 1, row);

    for (int i = row - 1; i >= 0; --i) {
        grayCode[row] = grayCode[i];
        grayCode[row][n-1] = true;
        row++;
    }
}

int main() {
    int n;
    cin >> n;

    int size = int(pow(2, n));
    vector<vector<bool>> grayCode(size, vector<bool>(n, false));

    int row = 1;
    make_grey_code(grayCode, n, row);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grayCode[i][j];
        }
        cout << '\n';
    }

    return 0;
}
