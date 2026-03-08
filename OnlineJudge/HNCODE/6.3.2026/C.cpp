#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BAI3"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b;
    for (auto &x : a) cin >> x;

    b = a;
    sort(b.begin(), b.end(), greater<ll>());

    umap<ll, queue<int>> pos;

    for (int i = 0; i < n; i++) pos[b[i]].push(i);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        p[i] = pos[a[i]].front();
        pos[a[i]].pop();
    }

    vector<int> lis;

    for (int x : p) {
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << n - lis.size();

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
