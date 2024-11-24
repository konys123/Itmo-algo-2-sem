#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> v;

int hash_1(string s) {
    const int p = 236;
    int pow_p = 1;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res += (s[i] * pow_p)% 900019;
        pow_p *= p;
    }
    return res % 900019;
}

int hash_2(string s) {
    const int p = 7;
    int pow_p = 1;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res += ((s[i] - 'a' + 1) * pow_p)% 900019;
        pow_p *= p;
    }
    return res % 900019;
}

void kykyshka(string cur_s, string s, int x, int k) {
    int h1 = hash_1(cur_s);
    if (v[x][h1] == "") {
        v[x][h1] = cur_s;
        return;
    }
    int h2 = hash_2(cur_s);
    if (v[x][h2] == "") {
        v[x][h2] = cur_s;
        return;
    }
    if (k > 10) {
        exit(5);
    }
    if (v[x][h1] != s and v[x][h1] != cur_s) {
        string tmp = v[x][h1];
        v[x][h1] = cur_s;
        k++;
        kykyshka(tmp, s, x, k);
    }

    if (v[x][h2] != s and v[x][h2] != cur_s) {
        string tmp = v[x][h2];
        v[x][h2] = cur_s;
        k++;
        kykyshka(tmp, s, x, k);
    }
    //exit(3);
}

int main() {
    int n;
    cin >> n;

    v.resize(3, vector<string>(900019));
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            kykyshka(s, s, j, 0);
        }
    }
    int st1 = n * 3, st2 = n * 3, st3 = n * 3;
    for (int i = 0; i < 900019; ++i) {
        if (v[0][i] == v[1][i] and v[0][i] == v[2][i] and v[0][i] != "") {
            st1 -= 3;
            st2 -= 3;
            st3 -= 3;
        } else if (v[0][i] == v[1][i] and v[0][i] != "") {
            st1 -= 2;
            st2 -= 2;
        } else if (v[0][i] == v[2][i] and v[0][i] != "") {
            st1 -= 2;
            st3 -= 2;
        } else if (v[1][i] == v[2][i] and v[1][i] != "") {
            st2 -= 2;
            st3 -= 2;
        }
    }

    cout << st1 << ' ' << st2 << ' ' << st3;

    return 0;
}
