const int MAXN = 1e5 + 5;
struct edge {
	int u, v;
	ll w;
};

vector<edge> edges;
vector<pii> g[MAXN];

void bellmanfordEdge(int src) {
    // Kh?i t?o
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;
	
	bool ncyclic = false;
    // Relax n-1 l?n
    for (int i = 1; i <= n; i++) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
                if (i == n) {
                	ncyclic = true;
                	break;
				}
            }
        }
        if (ncyclic) break;
        if (!changed) break; // t?i uu
    }
}

void bellmanfordVertex(int src) {
    // Kh?i t?o
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;
	
	bool ncyclic = false;
    // Relax n-1 l?n
    for (int i = 1; i <= n - 1; i++) {
        bool changed = false;
        for (int u = 1; u <= n; u++) {
            if (dist[u] == INF) continue;
            for (auto &p : g[u]) {
                int v = p.first;
                int w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                    if (i == n) {
                    	ncyclic = true;
                    	break;
					}
                }
            }
        }
        if (ncylic) break;
        if (!changed) break;
    }
}

