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
// Created: 2026-03-22 20:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "50"

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

#define int long long

const ll MOD = 1e9 + 7;
const ll BASE = 113;
const int MAXN = 200000 + 5;

ll pw[MAXN];

struct Node {
    int val;
    int prior;
    int sz;
    ll hash;
    Node *l, *r;
    
    Node(int v) {
        val = v + 67;
        prior = mt();
        sz = 1;
        hash = v;
        l = r = nullptr;
    }
};

int sz(Node* t) {
    return t ? t->sz : 0;
}

ll get_hash(Node* t) {
    return t ? t->hash : 0;
}

void upd(Node* t) {
    if (!t) return;
    
    t->sz = 1 + sz(t->l) + sz(t->r);
    
    ll left_hash = get_hash(t->l);
    ll right_hash = get_hash(t->r);
    
    int ls = sz(t->l);
    
    ll res = 0;
    
    res = left_hash;
    res = (res + t->val * pw[ls]) % MOD;
    res = (res + right_hash * pw[ls + 1]) % MOD;
    
    t->hash = res;
}

void split(Node* t, Node*& l, Node*& r, int k) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    
    if (sz(t->l) >= k) {
        split(t->l, l, t->l, k);
        r = t;
        upd(r);
    } else {
        split(t->r, t->r, r, k - sz(t->l) - 1);
        l = t;
        upd(l);
    }
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

Node* build(string &s) {
    Node* root = nullptr;
    for (char c : s) {
        root = merge(root, new Node(c - '0'));
    }
    return root;
}

ll get_sub_hash(Node*& root, int l, int r) {
    Node *A, *B, *C;
    
    split(root, A, B, l - 1);
    split(B, B, C, r - l + 1);
    
    ll res = get_hash(B);
    
    root = merge(A, merge(B, C));
    
    return res;
}

void move_to_front(Node*& root, int i) {
    Node *A, *B, *C;
    
    split(root, A, B, i - 1);
    split(B, B, C, 1);
    
    root = merge(B, merge(A, C));
}

void testcase() {
    string s;
    cin >> s;
    
    int n, q;
    n = s.len();
    cin >> q;
    
    pw[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pw[i] = (pw[i-1] * BASE) % MOD;
    
    Node* root = build(s);
    
    while (q--) {
        char type;
        cin >> type;
        
        if (type == '-') {
            int pos;
            cin >> pos;
            move_to_front(root, pos);
        } else {
            int l1, l2, k;
            cin >> l1 >> l2 >> k;
            
            ll h1 = get_sub_hash(root, l1, l1 + k - 1);
            ll h2 = get_sub_hash(root, l2, l2 + k - 1);
            
            if (h1 == h2)
                cout << "YES" << el;
            else
                cout << "NO" << el;
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