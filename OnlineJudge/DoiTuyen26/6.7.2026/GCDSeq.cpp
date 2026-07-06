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
// Created: 2026-07-06 10:00

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "GCDSeq"

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

const int MAXN = 2e5 + 5;
const int LOG = 30;

int n;

vector<int> a(MAXN, 0);

void testcase() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[0];
    
    bool check = true;
    for (int i = 0 ; i < n; i++) {
        if (a[i] != a[i + 1]) {
            check = false;
            break;
        }
    }

    if (check) {
        cout << 0;
        return;
    }

    int cnt = 0;

    while (!check) {
        ++cnt;
        for (int i = 0; i < n; i++) {
            a[i] = __gcd(a[i], a[i + 1]);
        }
        a[n] = a[0];
        check = true;
        for (int i = 0 ; i < n; i++) {
            if (a[i] != a[i + 1]) {
                check = false;
                break;
            }
        }
    }

    cout << cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}