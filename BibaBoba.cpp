#include <iostream>
#include <vector>

using namespace std;

int hash_(int value){
    if (value < 0){
        return (value + 1000000000)%10000019;
    }
    else{
        return (value)%10000019;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> heshiki(10000019, 0);

    for (int j = 0; j < n; ++j) {
        cin >> arr[j];
        int d = arr[j] - j;
        int h = hash_(d);
        heshiki[h]++;
    }

    int ans = 0;

    for (int i = 0; i < 10000019; ++i) {
        ans += (heshiki[i] * (heshiki[i] - 1)) / 2;
    }

    cout << ans;

    return 0;
}
