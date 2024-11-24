#include <iostream>
#include <string>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string text;
    cin >> text;
    int ans = 0;

    for (int l = 0; l < m; ++l) {
        int i,j,k;
        cin >> i >> j >> k;
        bool c = true;
        for (int i1 = 0; i1 < k; ++i1) {
            if (text[i+i1-1] != text[j+i1-1]){
                c = false;
                break;
            }
        }
        if (c){
            ++ans;
        }

    }

    cout << ans;

    return 0;
}
