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

// Author: Fua

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6 + 5;
int p[MAXN]; // largest prime divisble 

void sieve() {
    p[0] = p[1] = 0;
    for (int i = 2; i < MAXN; i++) p[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (p[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                p[j] = i;
            }
        }
    }
}

int cnt(int val) {
    int res = 0;
    while (val > 1) {
        ++res;
        val /= p[val];
    }
    return res;
}

bool check(int val) {
    if (p[val] == val || val <= 1) return false;
    int last = p[val];
    while (val > 1) {
        if (p[val] != last) {
            return true;
        }
        val /= last;
    }
    return false;
}

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    {
        bool bruh = false;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                bruh = true;
                break;
            }
        }
        if (!bruh) {
            cout << "Bob" << el;
            return;
        }
    }

    int res = 0;
    bool ok = false;

    for (int i = 1; i <= n; i++) {
        if (check(a[i])) ok = true;
    }

    if (ok) {
        cout << "Alice" << el;
        return;
    } else {
        for (int i = 1; i < n; i++) {
            if (p[a[i]] > p[a[i + 1]]) {
                cout << "Alice" << el;
                return;
            }
        }
        cout << "Bob" << el;
        return;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}