#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<int> arr_1(n + 1, 0);
    unordered_map<int, int> last_index;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (last_index.find(arr[i]) == last_index.end() or last_index[arr[i]] < i - 1) {
            arr_1[i] = arr_1[i - 1] + 1;
        } else {
            arr_1[i] = arr_1[i - 1];
        }
        last_index[arr[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << arr_1[r] - arr_1[l - 1] << '\n';
    }

    return 0;
}
