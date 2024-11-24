#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

vector<int> match; // Для хранения пар вершин из паросочетания
vector<vector<int>> adj; // Список смежности для двудольного графа

bool bfs(vector<vector<int>>& adj, vector<int>& pairU, vector<int>& pairV, vector<int>& dist) {
    queue<int> q;
    for (int u = 0; u < pairU.size(); ++u) {
        if (pairU[u] == -1) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }

    bool found_augmenting_path = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] < INT_MAX) {
            for (int v : adj[u]) {
                if (pairV[v] == -1) {
                    found_augmenting_path = true;
                } else if (dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return found_augmenting_path;
}

bool dfs(int u, vector<vector<int>>& adj, vector<int>& pairU, vector<int>& pairV, vector<int>& dist) {
    for (int v : adj[u]) {
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v], adj, pairU, pairV, dist))) {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }
    dist[u] = INT_MAX;
    return false;
}

int hopcroft_karp(vector<vector<int>>& adj, int U, int V) {
    vector<int> pairU(U, -1);
    vector<int> pairV(V, -1);
    vector<int> dist(U);

    int matching = 0;
    while (bfs(adj, pairU, pairV, dist)) {
        for (int u = 0; u < U; ++u) {
            if (pairU[u] == -1 && dfs(u, adj, pairU, pairV, dist)) {
                ++matching;
            }
        }
    }

    return matching;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    // Инициализация списка смежности для двудольного графа
    adj.resize(N);

    // Считываем запретные клетки и строим граф
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1); // Добавляем ребро из вершины x-1 первой доли в вершину y-1 второй доли
    }

    // Вычисляем размеры долей U и V
    int U = N;
    int V = M;

    // Находим максимальное паросочетание
    int maxMatching = hopcroft_karp(adj, U, V);

    // Максимальное количество покрытых клеток конфетами 2x1
    int maxCoveredCells = 2 * maxMatching;
    cout << "Максимальное количество покрытых клеток: " << maxCoveredCells << endl;

    return 0;
}
