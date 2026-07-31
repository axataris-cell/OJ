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
// Created: 2026-07-29 16:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TachTu"

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
const int MOD = 1337377;

struct Trie {
    struct Node {
        int nxt[26];
        int cnt;
        int exist;
    } trie[MAXNODE];

    int sz = 0;

    void addstring(string &s) {
        int p = 0;
        ++trie[p].cnt;
        for (auto ch : s) {
            int c = ch - 'a';
            if (!trie[p].nxt[c]) trie[p].nxt[c] = ++sz;
            p = trie[p].nxt[c];
            ++trie[p].cnt;
        }
        ++trie[p].exist;
    }

    void delstring(string &s) {
        int p = 0;
        --trie[p].cnt;
        for (auto ch : s) {
            int c = ch - 'a';
            p = trie[p].nxt[c];
            --trie[p].cnt;
        }
        --trie[p].exist;
    }
};

Trie trie;

void testcase() {
    string s; cin >> s;
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        string t; cin >> t;
        trie.addstring(t);
    }

    int l = s.size();
    vector<int> dp(l + 5, 0);
    
    dp[l] = 1; 

    for (int i = l - 1; i >= 0; i--) {
        int v = 0;

        for (int j = i; j < l && j < i + 100; j++) {
            int c = s[j] - 'a';

            if (!trie.trie[v].nxt[c]) break;

            v = trie.trie[v].nxt[c];

            if (trie.trie[v].exist) {
                dp[i] += dp[j + 1] * trie.trie[v].exist;
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[0];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}