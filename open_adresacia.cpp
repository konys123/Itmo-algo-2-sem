#include <iostream>
#include <vector>

using namespace std;

int hash_(int value) {
    if (value >= 0) {
        return value % 1000019;
    }
    exit(9);
    return (value + 1000003001) % 1000019;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n*5, {-1,-1});

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int h = hash_(x);


        while (arr[h].first != -1) {
            h = (h + 1) % n*5;
        }
        arr[h] = {x,y};

    }
    for (int i = 0; i < n * 5; ++i) {
        int k = 0;
        int x,y1,y2;
        if (arr[i] != )
    }

    if (count <= 3) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
