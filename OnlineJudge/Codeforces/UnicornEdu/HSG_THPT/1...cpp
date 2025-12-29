#include <bits/stdc++.h>
#define umap unordered_map
#define ll long long

using namespace std;

struct segment {
    ll r, a, b;
};

ll xs, ys, xe, ye;
int n;

vector<segment> segs;
umap<ll, vector<int>> hang;

int findSeg(ll x, ll y) {
    for (int i = 0; i < n; i++) {
        if (segs[i].r == x && segs[i].a <= y && y <= segs[i].b) {
            return i;
        }
    }
    return -1;
}

bool valid(const segment &u, const segment &v) {
    if (llabs(u.r - v.r) > 1) return false;
    if (max(u.a, v.a) > min(u.b, v.b) + 1) return false;
    return true;
}

int bfs(int start, int end) {
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == end) return dist[u];

        const segment &cur = segs[u];

        for (ll nr = cur.r - 1; nr <= cur.r + 1; nr++) {
            if (!hang.count(nr)) continue;

            for (int v : hang[nr]) {
                if (dist[v] != -1) continue;
                if (segs[v].a > cur.b + 1) break; // T?I UU QUAN TR?NG
                if (!valid(cur, segs[v])) continue;

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

void testcase() {
    cin >> xs >> ys >> xe >> ye;
    cin >> n;

    segs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].r >> segs[i].a >> segs[i].b;
    }

    hang.clear();
    hang.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        hang[segs[i].r].push_back(i);
    }

    // FIX SORT
    for (auto &p : hang) {
        auto &v = p.second;
        sort(v.begin(), v.end(), [&](int i, int j) {
            return segs[i].a < segs[j].a;
        });
    }

    int start = findSeg(xs, ys);
    int end = findSeg(xe, ye);

    if (start == -1 || end == -1) {
        cout << -1;
        return;
    }

    cout << bfs(start, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    testcase();
    return 0;
}
