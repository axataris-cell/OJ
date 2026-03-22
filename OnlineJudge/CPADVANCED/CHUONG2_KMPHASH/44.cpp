#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-21 22:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 5005;
const int BASE = mt() % 551322 + 41412;
const int MOD = 1e9 + 9;
const int BASE2 = mt() % 412512 + 61341;
const int MOD2 = 1e9 + 7;
const int BASE3 = mt() % 713421 + 51231;
const int MOD3 = 998244353;

string s;
int n;
int H[MAXN], P[MAXN];
int H2[MAXN], P2[MAXN];
int H3[MAXN], P3[MAXN];

void build() {
    P[0] = 1;
    P2[0] = 1;
    P3[0] = 1;
    for (int i = 1; i <= n; i++) {
        H[i] = (H[i-1] * BASE + (s[i] - 'a' + 1)) % MOD;
        P[i] = P[i-1] * BASE % MOD;

        H2[i] = (H2[i-1] * BASE2 + (s[i] - 'a' + 1)) % MOD2;
        P2[i] = P2[i-1] * BASE2 % MOD2;

        H3[i] = (H3[i-1] * BASE3 + (s[i] - 'a' + 1)) % MOD3;
        P3[i] = P3[i-1] * BASE3 % MOD3;
    }
}

tuple<int,int,int> get(int l, int r) {
    int x = (H[r] - H[l-1] * P[r-l+1] % MOD + MOD) % MOD;
    int y = (H2[r] - H2[l-1] * P2[r-l+1] % MOD2 + MOD2) % MOD2;
    int z = (H3[r] - H3[l-1] * P3[r-l+1] % MOD3 + MOD3) % MOD3;
    return {x, y, z};
}

bool check(int len) {
    umap<string ,int> pos;

    for (int i = 1; i + len - 1 <= n; i++) {
        auto [x,y,z] = get(i, i + len - 1);
        string key = to_string(x) + "#" + to_string(y) + "#" + to_string(z);

        if (pos.count(key)) {
            if (i - pos[key] >= len) return true;
        } else {
            pos[key] = i;
        }
    }

    return false;
}

void testcase() {
    cin >> n;
    cin >> s;

    n = s.length();
    s = " " + s;

    build();

    int l = 1, r = n, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}