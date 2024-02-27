#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grades(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M));
    string line;

    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < M; ++j) {
            if (line[j] == '5') {
                grades[i][j] = 1;
            } else {
                grades[i][j] = 0;
            }
            dp[i][j] = grades[i][j];
            if (i != 0 and j != 0 and grades[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }

    int max_size = 0, max_i = 0, max_j = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dp[i][j] >= max_size) {
                max_size = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << max_size << " " << (max_i - max_size + 1) + 1 << " " << (max_j - max_size + 1) + 1;

    return 0;
}