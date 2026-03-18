#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegH {
    ll row, l, r;
};

struct SegV {
    ll col, l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    int K;
    cin >> K;

    map<ll, vector<pair<ll,ll>>> H, V;

    for (int i = 0; i < K; i++) {
        ll r, c;
        char d;
        cin >> r >> c >> d;

        if (d == 'N') V[c].push_back({r, m});
        else if (d == 'S') V[c].push_back({0, r});
        else if (d == 'E') H[r].push_back({c, n});
        else H[r].push_back({0, c});
    }

    auto merge = [&](vector<pair<ll,ll>> &a) {
        sort(a.begin(), a.end());
        vector<pair<ll,ll>> res;
        for (auto &x : a) {
            if (res.empty() || res.back().second < x.first)
                res.push_back(x);
            else
                res.back().second = max(res.back().second, x.second);
        }
        a = res;
    };

    for (auto &x : H) merge(x.second);
    for (auto &x : V) merge(x.second);

    vector<SegH> hs;
    vector<SegV> vs;

    ll total = 0;

    for (auto &x : H) {
        for (auto &seg : x.second) {
            hs.push_back({x.first, seg.first, seg.second});
            total += seg.second - seg.first + 1;
        }
    }

    for (auto &x : V) {
        for (auto &seg : x.second) {
            vs.push_back({x.first, seg.first, seg.second});
            total += seg.second - seg.first + 1;
        }
    }

    // Sweep line
    vector<ll> ys;

    for (auto &h : hs) ys.push_back(h.row);
    for (auto &v : vs) {
        ys.push_back(v.l);
        ys.push_back(v.r);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto get = [&](ll y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    int SZ = ys.size();
    vector<int> bit(SZ + 5);

    auto update = [&](int i, int v) {
        for (; i <= SZ; i += i & -i) bit[i] += v;
    };

    auto query = [&](int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    };

    struct Event {
        ll x;
        int type;
        ll y1, y2;
    };

    vector<Event> ev;

    // vertical segments → add/remove
    for (auto &v : vs) {
        ev.push_back({v.col, 0, v.l, v.r}); // add
        ev.push_back({v.col + 1, 1, v.l, v.r}); // remove
    }

    // horizontal → query
    for (auto &h : hs) {
        ev.push_back({h.l, 2, h.row, 0});
        ev.push_back({h.r + 1, 3, h.row, 0});
    }

    sort(ev.begin(), ev.end(), [](auto &a, auto &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type < b.type;
    });

    ll intersect = 0;

    for (auto &e : ev) {
        if (e.type == 0) {
            update(get(e.y1), 1);
            update(get(e.y2) + 1, -1);
        }
        else if (e.type == 1) {
            update(get(e.y1), -1);
            update(get(e.y2) + 1, 1);
        }
        else if (e.type == 2) {
            intersect -= query(get(e.y1));
        }
        else {
            intersect += query(get(e.y1));
        }
    }

    cout << total - intersect << '\n';
}