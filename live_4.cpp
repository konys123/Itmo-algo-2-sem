#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> z(n);
    vector<int> prefix(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> z[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = z[i]; j > 0; --j) {
            if (prefix[i + j - 1] != 0) {break;}
            prefix[i + j - 1] = j;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << prefix[i] << ' ';
    }

    return 0;
}
