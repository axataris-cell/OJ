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
// Created: 2026-04-20 08:10

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2162D"

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
    // query 1 -> n => tìm được chênh lệnh r - l + 1
    // BS cho 2 phía l, r: đầu tiên cố định l = 1, bs cho r sao cho tổng chênh lệch đúng r - l + 1
    // rồi sau đó BS cho l
    // tổng 2 * log(n) + 2 => 30 queries

    int rl1, rl2;
    cout << "1 " << 1 << ' ' << n << endl;
    cin >> rl1;
    cout << "2 " << 1 << ' ' << n << endl;
    cin >> rl2;

    int diff = rl2 - rl1; // r - l + 1   real

    int r = n;
    int l = 1;

    int _r = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        cout << "1 " << 1 << ' ' << mid << endl;
        int res1; cin >> res1;
        cout << "2 " << 1 << ' ' << mid << endl;
        int res2; cin >> res2;

        int cnt = res2 - res1;

        if (cnt > 0) {
            r = mid - 1;
        } else {
            _r = mid;
            l = mid + 1;
        }
    }
    
    cout << "! " << _r + 1 << ' ' << _r + diff << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}