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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

int n, k, s; 
int cnt = 0;
vector<int> path;

void solve(int v, int curs) {
	if (cnt >= k) return;
	
	if (curs == s) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << ' ';
		}
		cout << 0 << el;
		++cnt;
		return;
	}
	
	if (v <= 0 || curs > s) return;
	
	if (curs + (v * (v + 1) / 2) < s) return;
	
	if (curs + v <= s) {
		path.pb(v);
		solve(v - 1, curs + v);
		path.pop_back();
	}
	
	if (cnt < k) solve(v - 1, curs);
}

void testcase() {
	cin >> n >> k >> s;
	if (s > (n * (n + 1) / 2)) return;
	
	solve(n, 0);
	
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}
