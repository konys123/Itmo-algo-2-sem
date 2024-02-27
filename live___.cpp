#include <iostream>
#include <set>


using namespace std;

int main() {
    int n;
    cin >> n;
    set<long long > ss;
    long long arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ss.insert(arr[i]);
    }
    int first,last;
    for (int i = 0; i < ss.size(); ++i) {

    }
    return 0;
}