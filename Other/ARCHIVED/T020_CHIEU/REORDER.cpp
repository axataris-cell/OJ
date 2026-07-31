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
// Created: 2026-06-25 14:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "REORDER"

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
    vector<int> mp('z' - 'a' + 5, 0);
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) ++mp[s[i] - 'a'];
    string res = "";
    for (int rem = n; rem >= 1; rem--) { // remaining
        bool changed = false;
        for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++) {
            if (mp[i] > rem - mp[i]) {
                if (res.size() && res[res.size() - 1] == char(i + 'a')) continue;
                res += char(i + 'a');
                changed = true;
                --mp[i];
                break;
            }
        }
        if (changed) continue;
        for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++) {
            if (mp[i]) {
                if (res.size() && res[res.size() - 1] == char(i + 'a')) continue;
                res += char(i + 'a');
                changed = true;
                --mp[i];
                break;
            }
        }
    }
    cout << (res.size() == n ? res : "-1");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}