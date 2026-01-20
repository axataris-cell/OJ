#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME ""

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

const int MAXN = 1e3 + 5;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};


int n;

struct edge {
	int u, v;
	ld d; // distance
};

vector<pair<ld, ld>> points(MAXN);
vector<edge> edges;

void testcase() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    edges.clear();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ld dx = points[i].first - points[j].first;
            ld dy = points[i].second - points[j].second;
            edges.push_back({i, j, hypotl(dx, dy)});
        }
    }

    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.d < b.d;
    });

    DSU dsu(n);
    ld maxEdge = 0;
    int cnt = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            maxEdge = max(maxEdge, e.d);
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    cout << fixed << setprecision(6) << maxEdge / 2.0L;
    cerr << el;
    cerr << "1 2 3 4 alo alo mot hai ba bon online judge anh bạn nhìn thấy cái này k";
}


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
