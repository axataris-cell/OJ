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
// Created: 2026-03-24 15:24

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "130"

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

const int MAXN = 205;

int n;

vector<int> g[MAXN];
vector<int> deg(MAXN, 0);
vector<int> topo;
bool vis[MAXN];

void bfs() {
    pqueue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (q.size()) {
        int u = q.top(); q.pop();
        topo.pb(u);
        for (int v : g[u]) {
            if (deg[v] == 0) continue;
            if (--deg[v] == 0) q.push(v);
        }
    }
}

void testcase() {
    cin >> n;
    cin.ignore();
    string s;
    // là ai đã nghĩ ra cái input này ???? 
    while (getline(cin, s)) {
        stringstream ss(s);
        string i;
        int head = 0;
        int cnt = 0;
        while (ss >> i) {
            ++cnt;
            if (cnt == 1) head = stoi(i);
            else {
                g[head].pb(stoi(i));
                ++deg[stoi(i)];
            }
        }
    }

    bfs();

    for (auto x : topo) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}