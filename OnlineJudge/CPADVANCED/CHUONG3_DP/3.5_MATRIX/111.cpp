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
// Created: 2026-03-31 22:12

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "111"

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

using type = ll;

struct Matrix {
    vector<vector<type>> d;

    Matrix() = default;
    Matrix(int r, int c) : d(r, vector<type>(c)) {}
    Matrix(const vector<vector<type>> &_d) : d(_d) {}

    auto & operator [](int i) {return d[i];}
    const auto & operator [](int i) const {return d[i];}

    int row() const {return d.size();}
    int col() const {return d[0].size();}

    friend ostream & operator << (ostream &out, const Matrix &a) {
        for (auto x : a.d) {
            for (auto y : x) out << y << ' ';
            out << el;
        }
        return out;
    }

    static Matrix identity(ll n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        const Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int k = 0; k < a.col(); ++k)
                for (int j = 0; j < b.col(); ++j)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    static bool check(const Matrix &a, const Matrix &b) {return a.col() == b.row();}

    Matrix pow(long long exp) {
        assert(row() == col());

        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

void testcase() {
    int n, m, p, q; cin >> n >> m >> p >> q;
    vector<vector<type>> m1(n, vector<type>(m));
    vector<vector<type>> m2(p, vector<type>(q));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> m1[i][j];
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) cin >> m2[i][j];
    }
    Matrix a(m1), b(m2);

    if (Matrix::check(a, b)) cout << a * b;
    else cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
} 