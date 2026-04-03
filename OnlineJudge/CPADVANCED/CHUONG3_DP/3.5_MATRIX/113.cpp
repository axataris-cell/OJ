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
// Created: 2026-04-01 14:29

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "113"

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

ll MOD;

using type = ll;

struct Matrix {
    vector<vector<type>> d;

    Matrix() = default;
    Matrix(int r, int c) : d(r, vector<type>(c)) {}
    Matrix(const vector<vector<type>> &_d) : d(_d) {}

    auto & operator [](int i) { return d[i]; }
    const auto & operator [](int i) const { return d[i]; }

    int row() const { return d.size(); }
    int col() const { return d[0].size(); }

    friend ostream & operator << (ostream &out, const Matrix &a) {
        for (auto x : a.d) {
            for (auto y : x) out << y << ' ';
            out << el;
        }
        return out;
    }

    static Matrix identity(ll n) {
        Matrix a(n, n);
        for (int i = 0; i < n; ++i) a[i][i] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        const Matrix &a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int k = 0; k < a.col(); ++k)
                for (int j = 0; j < b.col(); ++j)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());

        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

void testcase() {
    ll n;
    cin >> n >> MOD;
    Matrix A({
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    });
    Matrix base(vector<vector<type>>({
        {2},
        {1},
        {1},
    }));
    if (n < 1) {
        cout << 1 << el;
        return;
    }
    Matrix res = A.pow(n - 2) * base;
    cout << res[0][0] % MOD << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}