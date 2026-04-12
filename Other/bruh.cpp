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
// Created: 2026-04-08 23:19

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "bruh"

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

struct BigNum {
    vector<int> d;

    BigNum(long long x = 0) {
        if (x == 0) d = {0};
        else {
            while (x) {
                d.push_back(x % 10);
                x /= 10;
            }
        }
    }

    void trim() {
        while (d.size() > 1 && d.back() == 0)
            d.pop_back();
    }

    string str() const {
        string s;
        for (int i = d.size() - 1; i >= 0; i--)
            s += char(d[i] + '0');
        return s;
    }

    void print() const {
        for (int i = d.size() - 1; i >= 0; i--)
            cout << d[i];
    }

    friend BigNum operator + (const BigNum &a, const BigNum &b) {
        BigNum c;
        c.d.clear();

        int carry = 0;
        int n = max(a.d.size(), b.d.size());

        for (int i = 0; i < n || carry; i++) {
            int sum = carry;

            if (i < a.d.size()) sum += a.d[i];
            if (i < b.d.size()) sum += b.d[i];

            c.d.push_back(sum % 10);
            carry = sum / 10;
        }

        return c;
    }

    BigNum& operator += (const BigNum &b) {
        *this = *this + b;
        return *this;
    }

    bool operator == (const BigNum &b) const {
        return d == b.d;
    }

    bool operator != (const BigNum &b) const {
        return d != b.d;
    }

    bool operator < (const BigNum &b) const {
        if (d.size() != b.d.size())
            return d.size() < b.d.size();

        for (int i = d.size() - 1; i >= 0; i--)
            if (d[i] != b.d[i])
                return d[i] < b.d[i];

        return false;
    }
};

void testcase() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}