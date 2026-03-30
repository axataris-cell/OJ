#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MAXN = 105;

int adj[MAXN][MAXN];
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));
vector<vector<int>> route(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int s, d, start_time;
    cin >> s >> d >> start_time;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];

    cin.ignore();

    for (int i = 1; i <= m; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        int t;
        ss >> t;

        int x;
        while (ss >> x)
            route[i].push_back(x);

        int cur = route[i][0];
        dist[i][cur] = t;

        for (int j = 1; j < route[i].size(); j++) {
            int u = route[i][j-1];
            int v = route[i][j];

            dist[i][v] = dist[i][u] + adj[u][v];
        }
    }

    // -------------------------
    // Câu 1: đến sớm nhất
    // -------------------------

    vector<int> best_time(n+1, INF);
    best_time[s] = start_time;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({start_time, s});

    while (!pq.empty()) {
        auto [cur_time, u] = pq.top();
        pq.pop();

        if (cur_time > best_time[u]) continue;

        for (int k = 1; k <= m; k++) {
            if (dist[k][u] < cur_time) continue;

            for (int v : route[k]) {
                if (dist[k][v] < dist[k][u]) continue;

                if (best_time[v] > dist[k][v]) {
                    best_time[v] = dist[k][v];
                    pq.push({best_time[v], v});
                }
            }
        }
    }

    int ans1 = best_time[d];

    // -------------------------
    // Câu 2: ít chuyển tuyến
    // -------------------------

    vector<int> best_transfer(n+1, INF);

    queue<pair<int,int>> q;
    best_transfer[s] = 0;
    q.push({s, -1});

    while (!q.empty()) {
        auto [u, last_train] = q.front();
        q.pop();

        for (int k = 1; k <= m; k++) {
            if (dist[k][u] < start_time) continue;

            int add = (k != last_train);

            for (int v : route[k]) {
                if (dist[k][v] < dist[k][u]) continue;

                if (best_transfer[v] > best_transfer[u] + add) {
                    best_transfer[v] = best_transfer[u] + add;
                    q.push({v, k});
                }
            }
        }
    }

    cout << ans1 << " " << best_transfer[d];
}