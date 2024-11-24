#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text, name;
    cin >> text >> name;

    int count = 0;
    vector<int> indexes;
    for (int i = 0; i < text.size(); ++i) {
        int cur = i;
        bool f = false;

        for (int j = 0; j < name.size(); ++j) {
            if (text[cur] != name[j]) {
                f = true;
                break;
            }
            ++cur;
        }

        if (!f) {
            ++count;
            indexes.push_back(i);
        }
    }

    cout << count << '\n';
    for (int i = 0; i < indexes.size(); ++i) {
        cout << indexes[i] << ' ';
    }


    return 0;
}
