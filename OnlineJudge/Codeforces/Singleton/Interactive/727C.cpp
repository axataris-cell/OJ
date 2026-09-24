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
// Created: 2026-04-17 08:43

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "727C"

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
    int n; cin >> n;
    int _n = n;
    if (_n % 2 == 0) n--;
    vector<int> arr(_n + 5); // original array
    vector<int> a(n + 5); // a[i] = ai + ai + 1.
    for (int i = 1; i <= n - 1; i++) {
        cout << "? " << i << ' ' << i + 1 << endl;
        cin >> a[i];
    }
    cout << "? " << n << ' ' << 1 << endl;
    cin >> a[n]; // a[n] = an + a1

    vector<int> d(n + 5);
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i + 1];
    }
    int minus = 0; // a1 - an
    for (int i = 1; i < n - 1; i+=2) {
        minus += d[i];
    }
    // a[n] = an + a1
    // minus = a1 - an
    // => a1 = ( a[n] + minus) / 2
    arr[1] = (a[n] + minus) / 2;
    for (int i = 2; i < n; i++) {
        arr[i] = a[i - 1] - arr[i - 1];
    }
    arr[n] = a[n] - arr[1];
    if (_n > n) {
        int last;
        cout << "? " << _n << ' ' << 1 << endl;
        cin >> last; // a1 + a_n
        arr[_n] = last - arr[1];
    }
    cout << "! ";
    for (int i = 1; i <= _n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}