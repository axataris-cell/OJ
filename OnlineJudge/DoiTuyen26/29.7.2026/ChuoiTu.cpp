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
// Created: 2026-07-29 09:21

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ChuoiTu"

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

const int MAXNODE = 1e6 + 5;

int res = 0;

struct Trie {
    struct Node {
        int nxt[26];
        int cnt;
        int exist;
    } trie[MAXNODE];

    int sz = 0;

    void insert(string &s) {
        int p = 0;
        for (auto &ch : s) {
            int c = ch - 'a';
            if (!trie[p].nxt[c]) trie[p].nxt[c] = ++sz;
            p = trie[p].nxt[c];
            ++trie[p].cnt;
        }
        ++trie[p].exist;
    }

    void delstring(string &s) {
        int p = 0;
        for (auto &ch : s) {
            int c = ch - 'a';
            p = trie[p].nxt[c];
            --trie[p].cnt;
        }
        --trie[p].exist;
    }

    void solve(int p, int cnt) {
        cnt += trie[p].exist;
        res = max(res, cnt);

        for (int i = 0; i < 26; i++)
            if (trie[p].nxt[i])
                solve(trie[p].nxt[i], cnt);
    }
};

Trie trie;

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        trie.insert(s);
    }
    trie.solve(0, 0);

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}