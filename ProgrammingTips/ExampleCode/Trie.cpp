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
// Created: 2026-03-31 08:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Trie"

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

struct Trie {
    struct Node {
        Node* child[26];
        int exist, cnt;
        Node() : cnt(1), exist(0) {
            for (int i = 0; i < 26; i++) child[i] = null;
        }
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void add(string s) {
        Node* p = root;
        for (const char &ch : s) {
            int c = ch - 'a';
            if (p->child[c] == null) {
                p->child[c] = new Node();
            }
            p = p->child[c];
            p->cnt++;
        }
        ++p->exist;
    }

    void delstring(string s) {
        Node* p = root;
        for (const char &ch : s) {
            int c = ch - 'a';
            --p->child[c]->cnt;
            p = p->child[c];
        }
        --p->exist;
    }

    void del(string s) {
        if (!exist(s)) return;
        delstring(s);
    }

    bool exist(string s) {
        Node* p = root;
        for (const char &ch : s) {
            int c = ch - 'a';
            if (p->child[c] == null || p->child[c]->cnt == 0) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }
};

void testcase() {
    Trie trie;
    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        string s; cin >> s;
        if (t == 1) {
            trie.add(s);
        } else if (t == 2) {
            trie.del(s);
        } else {
            cout << (trie.exist(s) ? "YES" : "NO") << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}