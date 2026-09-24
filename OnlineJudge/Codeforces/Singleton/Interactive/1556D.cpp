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
// Created: 2026-04-22 16:49

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1556D"

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

void testcase() {
    int n, k; cin >> n >> k;
    vector<int> OPAND(n + 1), OPOR(n + 1);

    // and 
    for (int i = 1; i < n; i++) {
        cout << "and " << i << ' ' << i + 1 << endl;
        cin >> OPAND[i];
    }
    // cout << "and " << n << ' ' << 1 << endl;
    // cin >> OPAND[n];

    // or
    for (int i = 1; i < n; i++) {
        cout << "or " << i << ' ' << i + 1 << endl;
        cin >> OPOR[i];
    }
    // cout << "or " << n << ' ' << 1 << endl;
    // cin >> OPOR[n];

    vector<int> a(n + 1, 0); //res

    // first three num
    int opand1 = OPAND[1];
    int opor1 = OPOR[1];
    int opand2 = OPAND[2];
    int opor2 = OPOR[2];
    int opand3;

    cout << "and 1 3" << endl;
    cin >> opand3;

    for (int i = 0; i < 64 && opand1 > 0; i++, opand1 >>= 1) {
        if (opand1 & 1) {
            a[1] += 1LL << i;
            a[2] += 1LL << i;
        }
    }
    for (int i = 0; i < 64 && opand2 > 0; i++, opand2 >>= 1) {
        if (opand2 & 1) {
            if (!(a[2] >> i & 1)) a[2] += 1LL << i;
            a[3] += 1LL << i;
        }
    }
    for (int i = 0; i < 64 && opor1 > 0; i++, opor1 >>= 1) {
        if (opor1 & 1) {
            if ((a[1] >> i & 1) || (a[2] >> i & 1)) continue;
            if (opor2 >> i & 1) {
                if (opand3 >> i & 1) {
                    a[1] += 1LL << i;
                    a[3] += 1LL << i;
                }
                else a[2] += 1LL << i;
            }
            else a[1] += 1LL << i;
        }
    }
    for (int i = 0; i < 64 && opor2 > 0; i++, opor2 >>= 1) {
        if (opor2 & 1) {
            if ((a[2] >> i & 1) || (a[3] >> i & 1)) continue;
            a[3] += 1LL << i;
        }
    }

    // int and13, or13;

    // cout << "and 1 3" << endl;
    // cin >> and13;

    // cout << "or 1 3" << endl;
    // cin >> or13;

    // int s12 = 2 * OPAND[1] + OPOR[1];
    // int s23 = 2 * OPAND[2] + OPOR[2];
    // int s31 = 2 * and13 + or13;

    // a[1] = (s12 + s31 - s23) / 2;
    // a[2] = s12 - a[1];
    // a[3] = s23 - a[2];

    // other numbers;
    for (int i = 4; i <= n; i++) {
        int opand = OPAND[i - 1];
        int opor = OPOR[i - 1];

        for (int bit = 0; bit < 64; bit++) {
            if (opand & 1) {
                a[i] += 1LL << bit;
            } else if (opor & 1) {
                if (!((a[i - 1] >> bit) & 1)) {
                    a[i] += 1LL << bit;
                }
            }
            opand >>= 1;
            opor >>= 1;
            if (opand <= 0 && opor <= 0) break;
        }
    }

    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // return;

    sort(a.begin() + 1, a.end());

    cout << "finish " << a[k] << endl;
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