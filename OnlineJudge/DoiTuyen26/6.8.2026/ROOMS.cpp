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
// Created: 2026-08-06 10:13

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ROOMS"

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

struct Conference {
    int s, f, id;
};

void testcase() {
    int n;
    cin >> n;

    vector<Conference> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
        a[i].id = i + 1;
    }

    sort(all(a), [](Conference x, Conference y) {
        if (x.s != y.s) return x.s < y.s;
        return x.f < y.f;
    });

    pqueue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<int>> room(1);

    for (auto [s, f, id] : a) {
        if (!pq.empty() && pq.top().fi <= s) {
            auto [_, room_id] = pq.top();
            pq.pop();

            room[room_id].pb(id);
            pq.push({f, room_id});
        } else {
            room.pb({});
            int room_id = (int)room.size() - 1;

            room[room_id].pb(id);
            pq.push({f, room_id});
        }
    }

    cout << room.size() - 1 << el;
    for (int i = 1; i < room.size(); i++) {
        for (int x : room[i])
            cout << x << ' ';
        cout << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}