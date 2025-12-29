#include <bits/stdc++.h>
using namespace std;

struct Segment {
    long long r, a, b;
};

long long x0, y0, x1, y1;
int n;

vector<Segment> segs;
unordered_map<long long, vector<int>> byRow;


void readInput() {
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;

    segs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].r >> segs[i].a >> segs[i].b;
    }
}

void buildByRow() {
    byRow.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        byRow[segs[i].r].push_back(i);
    }

    for (auto &p : byRow) {
        auto &v = p.second;
        sort(v.begin(), v.end(),
             [&](int i, int j) {
                 return segs[i].a < segs[j].a;
             });
    }
}

int findSegmentContainingPoint(long long x, long long y) {
    for (int i = 0; i < n; i++) {
        if (segs[i].r == x && segs[i].a <= y && y <= segs[i].b)
            return i;
    }
    return -1;
}

bool canConnect(const Segment &u, const Segment &v) {
    if (llabs(u.r - v.r) > 1) return false;
    if (max(u.a, v.a) > min(u.b, v.b) + 1) return false;
    return true;
}

int bfs(int start, int target) {
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) return dist[u];

        const Segment &cur = segs[u];

        for (long long nr = cur.r - 1; nr <= cur.r + 1; nr++) {
            if (!byRow.count(nr)) continue;

            for (int v : byRow[nr]) {
                if (dist[v] != -1) continue;
                if (!canConnect(cur, segs[v])) continue;

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    readInput();
    buildByRow();

    int start = findSegmentContainingPoint(x0, y0);
    int target = findSegmentContainingPoint(x1, y1);

    if (start == -1 || target == -1) {
        cout << -1;
        return 0;
    }

    cout << bfs(start, target);
    return 0;
}
