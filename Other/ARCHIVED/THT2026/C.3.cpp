#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

using State = vector<int>;

int N;

int get_idx(int r, int c) {
    return r * 4 + c;
}

bool is_target(const State& s) {
    for (int i = 0; i < 4 * N; i++) {
        if (s[i] != i + 1) return false;
    }
    return true;
}

struct Node {
    State s;
    vector<vector<int>> path;
};

void testcase() {
    State init(4 * N);

    for (int i = 0; i < 4 * N; i++) cin >> init[i];

    queue<Node> q;
    q.push({init, {}});

    map<State, bool> vis;
    vis[init] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (is_target(curr.s)) {
            cout << curr.path.size() << el;

            for (auto &p : curr.path) {
                cout << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << el;
            }

            return;
        }

        int b_idx = -1;

        for (int i = 0; i < 4 * N; i++) {
            if (curr.s[i] == 4 * N) b_idx = i;
        }

        int r = b_idx / 4;
        int c = b_idx % 4;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < 4) {
                State next_s = curr.s;

                int n_idx = get_idx(nr, nc);

                swap(next_s[b_idx], next_s[n_idx]);

                if (!vis[next_s]) {
                    vis[next_s] = true;

                    auto next_path = curr.path;
                    next_path.pb({r + 1, c + 1, nr + 1, nc + 1});

                    q.push({next_s, next_path});
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;

    cin >> N;

    while (t--)
        testcase();

    return 0;
}