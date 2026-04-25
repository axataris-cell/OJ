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
// Created: 2026-04-24 06:42

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

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

const int MAXN = 3e5 + 5;

vector<int> a(MAXN, 0);
vector<int> pref(4 * MAXN, 0);
vector<int> suff(4 * MAXN, 0);

void updateSF(int id, int l, int r, int pos, int val) {
    if (l == r) {
        suff[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) updateSF(id << 1, l, mid, pos, val);
    else updateSF(id << 1 | 1, mid + 1, r, pos, val);

    suff[id] = suff[id << 1] + suff[id << 1 | 1];
}

void updatePF(int id, int l, int r, int pos, int val) {
    if (l == r ){
        pref[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) updatePF(id << 1, l, mid, pos, val);
    else updatePF(id << 1 | 1, mid + 1, r, pos, val);

    pref[id] = pref[id << 1] + pref[id << 1 | 1];
}

int querySF(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return suff[id];
    }
    int mid = (l + r) / 2;
    return querySF(id << 1, l, mid, ql, qr) + querySF(id << 1 | 1, mid + 1, r, ql, qr);
}

int queryPF(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return pref[id];
    }
    int mid = (l + r) / 2;
    return queryPF(id << 1, l, mid, ql, qr) + queryPF(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n; cin >> n;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(all(b));
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    if (n <= 2) {
        cout << 0;
        return;
    }

    for (int i = 2; i <= n; i++) {
        updateSF(1, 0, n, a[i], 1);
    }
    updatePF(1, 0, n, a[1], 1);

    int res = 0;
    for (int i = 2; i < n; i++) {
        updateSF(1, 0, n, a[i], -1);
        
        // Tập A: a[left] <= a[i] và a[right] <= a[i]
        int L_le = queryPF(1, 0, n, 0, a[i]);
        int R_le = querySF(1, 0, n, 0, a[i]);
        
        // Tập B: a[left] >= a[i] và a[right] >= a[i]
        int L_ge = queryPF(1, 0, n, a[i], n);
        int R_ge = querySF(1, 0, n, a[i], n);
        
        // Giao của A và B: a[left] == a[i] và a[right] == a[i]
        int L_eq = queryPF(1, 0, n, a[i], a[i]);
        int R_eq = querySF(1, 0, n, a[i], a[i]);
        
        // Nguyên lý bù trừ (áp dụng quy tắc nhân)
        res += (L_le * R_le) + (L_ge * R_ge) - (L_eq * R_eq);
        
        updatePF(1, 0, n, a[i], 1);
    }

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