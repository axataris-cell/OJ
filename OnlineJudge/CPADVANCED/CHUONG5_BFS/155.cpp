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
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "155"

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

struct Vertex {
    int z, s, m;

    bool operator==(const Vertex &o) const {
        return z == o.z && s == o.s && m == o.m;
    }
};

struct VertexHash {
    size_t operator()(const Vertex &v) const {
        size_t seed = 0;
        seed ^= hash<int>()(v.z) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash<int>()(v.s) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash<int>()(v.m) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

Vertex add(const Vertex &x, const Vertex &y) {
    return {x.z + y.z, x.s + y.s, x.m + y.m};
}

Vertex subtract(const Vertex &x, const Vertex &y) {
    return {x.z - y.z, x.s - y.s, x.m - y.m};
}

bool valid(const Vertex &u) {
    return u.z >= 0 && u.s >= 0 && u.m >= 0;
}

bool canAfford(const Vertex &u, const Vertex &accept) {
    return u.z >= accept.z && u.s >= accept.s && u.m >= accept.m;
}

void testcase() {
    int k;
    cin >> k;

    Vertex start, accept;
    cin >> start.z >> start.s >> start.m;
    cin >> accept.z >> accept.s >> accept.m;

    vector<pair<Vertex, Vertex>> conversion;
    Vertex a, b;
    while (cin >> a.z >> a.s >> a.m >> b.z >> b.s >> b.m)
        conversion.pb({a, b});

    umap<Vertex, int, VertexHash> dist;
    vector<Vertex> res;

    queue<Vertex> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        Vertex u = q.front(); q.pop();
        int d = dist[u];

        if (canAfford(u, accept))
            res.pb(u);

        if (d >= k) continue;

        for (const auto& con : conversion) {
            Vertex diff = subtract(u, con.fi);
            if (!valid(diff)) continue;
            Vertex v = add(diff, con.se);
            if (!valid(v)) continue;
            if (dist.find(v) == dist.end()) {
                dist[v] = d + 1;
                q.push(v);
            }
        }
    }

    if (res.empty()) {
        cout << -1 << el;
        return;
    }

    sort(all(res), [&](const Vertex &x, const Vertex &y) {
        if (dist[x] != dist[y]) return dist[x] < dist[y];
        if (x.z != y.z) return x.z < y.z;
        if (x.s != y.s) return x.s < y.s;
        return x.m < y.m;
    });

    cout << res.size() << el;
    for (const Vertex& u : res)
        cout << u.z << ' ' << u.s << ' ' << u.m << ' ' << dist[u] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}