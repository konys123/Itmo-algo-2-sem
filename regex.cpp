#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int x;
    cin >> x;
    cin.ignore();

    for (int i = 0; i < x; ++i) {
        string n;
        getline(cin, n);
        regex re(
                R"([A-Z][a-z]* [A-Z][a-z]* [A-Z][a-z]* [0-9]{2} ((\+7[0-9]{10})|(\+7\([0-9]{3}\)[0-9]{3}-[0-9]{4})|(7[0-9]{10})|(8[0-9]{10})|(\+7\([0-9]{3}\)-[0-9]{3}-[0-9]{2}-[0-9]{2})) g\.[A-Z]{3}, ul\.[A-Z][a-z]*, d\.[0-9]{1,500})");
        if (regex_match(n, re)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
