#include <iostream>
#include <vector>

using namespace std;

int hash_(int value){
    return value%8191;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(8191,0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[hash_(x)] = x;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (arr[hash_(x)] == 0){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
