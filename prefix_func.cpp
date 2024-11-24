#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text;
    cin >> text;

    int n = text.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 and text[i] != text[j]) {
            j = pi[j - 1];
        }
        if (text[i] == text[j]) {
            ++j;
        }
        pi[i] = j;
    }

    for (int i = 0; i < pi.size(); ++i) {
        cout << pi[i] << ' ';
    }

    return 0;
}
