#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 200; // Максимальное количество вершин в графе (N*M)
vector<int> adj[MAXN];
int match[MAXN];
bool visited[MAXN];

bool bpm(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || bpm(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int n) {
    memset(match, -1, sizeof(match));
    int maxMatching = 0;
    for (int u = 0; u < n; ++u) {
        memset(visited, false, sizeof(visited));
        if (bpm(u)) {
            maxMatching++;
        }
    }
    return maxMatching;
}

int main() {
    int N, M;
    cin >> N >> M;

    int Q;
    cin >> Q;

    vector<vector<bool>> blocked(N, vector<bool>(M, false));

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        blocked[x - 1][y - 1] = true; // Запоминаем зачеркнутые клетки (перевод из 1-based в 0-based)
    }

    // Построение графа
    int nodeCount = N * M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (!blocked[r][c]) {
                int u = r * M + c; // Вершина для верхней части конфеты
                if ((r + 1) < N && !blocked[r + 1][c]) {
                    int v = (r + 1) * M + c; // Вершина для нижней части конфеты
                    adj[u].push_back(v);
                }
            }
        }
    }

    // Находим максимальное паросочетание
    int maxMatching = maxBPM(nodeCount);

    // Выводим результат (количество покрытых клеток)
    cout << 2 * maxMatching << endl; // Умножаем на 2, так как каждая конфета покрывает 2 клетки

    return 0;
}
