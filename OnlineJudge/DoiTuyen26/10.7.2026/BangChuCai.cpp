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
// Created: 2026-07-10 08:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BangChuCai"

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

void testcase() {
    int n, k; cin >> n >> k;
    vector<string> words(n + 1);
    vector<vector<bool>> g('z' - 'a' + 1, vector<bool>('z' - 'a' + 1, false));
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }

    for (int i = 1; i < n; i++) {
        string &a = words[i];
        string &b = words[i + 1];

        int len = min(a.length(), b.length());
        int pos = -1;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                pos = j;
                break;
            }
        }

        if (pos == -1) {
            if (a.length() > b.length()) {
                cout << "INVALID";
                return;
            }
        }
        else {
            g[a[pos] - 'a'][b[pos] - 'a'] = true;
        }
    }

    vector<int> deg(k, 0);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (g[i][j]) deg[j]++;



    vector<int> topo;

    queue<int> q;

    for (int i = 0; i < k; i++)
        if (deg[i] == 0)
            q.push(i);

    bool unique = true;

    while (q.size()) {
        if (q.size() > 1) unique = false;
        int u = q.front(); q.pop();
        topo.pb(u);
        for (int i = 0; i <= 'z' - 'a'; i++) {
            if (!g[u][i]) continue;
            if (--deg[i] == 0) q.push(i);
        }
    }

    if ((int)topo.size() != k) {
        cout << "INVALID";
        return;
    }

    if (!unique) {
        cout << "MULTIPLE";
        return;
    }

    for (int x : topo)
        cout << char(x + 'a');
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}