#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<long long>& d, int x, int n) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l+r)/2;
        if (d[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {

    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<long long > d(n + 1, 10000000000);
    d[0] = -10000000000;
    int length = 0;

    for (int i = 0; i < n; ++i) {
        int j = binary_search(d, heights[i], n + 1);
        if (d[j - 1] < heights[i] and heights[i] < d[j]) {
            d[j] = heights[i];
            length = max(length, j);
        }
    }

    cout << length;

    return 0;
}