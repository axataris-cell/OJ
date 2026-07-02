#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-19 21:54

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

string norm(string s) {
    bool neg = false;
    if (!s.empty() && s[0] == '-') {
        neg = true;
        s = s.substr(1);
    }
    while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
    if (neg && s != "0") s = "-" + s;
    return s;
}

bool ge_abs(string a, string b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}

string add_abs(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    int carry = 0;

    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int x = (i < a.size() ? a[i] - '0' : 0);
        int y = (i < b.size() ? b[i] - '0' : 0);
        int cur = x + y + carry;
        res.push_back(cur % 10 + '0');
        carry = cur / 10;
    }

    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return norm(res);
}

string sub_abs(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    int carry = 0;

    for (int i = 0; i < a.size(); i++) {
        int x = a[i] - '0';
        int y = (i < b.size() ? b[i] - '0' : 0);
        int cur = x - y - carry;
        if (cur < 0) {
            cur += 10;
            carry = 1;
        } else carry = 0;
        res.push_back(cur + '0');
    }

    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return norm(res);
}

string add(string a, string b) {
    bool na = (a[0] == '-');
    bool nb = (b[0] == '-');

    if (na) a = a.substr(1);
    if (nb) b = b.substr(1);

    if (na == nb) {
        string res = add_abs(a, b);
        if (na && res != "0") res = "-" + res;
        return res;
    } else {
        if (ge_abs(a, b)) {
            string res = sub_abs(a, b);
            if (na && res != "0") res = "-" + res;
            return res;
        } else {
            string res = sub_abs(b, a);
            if (nb && res != "0") res = "-" + res;
            return res;
        }
    }
}

string sub(string a, string b) {
    if (b[0] == '-') b = b.substr(1);
    else b = "-" + b;
    return add(a, b);
}

string div2(string s) {
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        s = s.substr(1);
    }

    string res;
    int carry = 0;

    for (char c : s) {
        int cur = carry * 10 + (c - '0');
        res.push_back(cur / 2 + '0');
        carry = cur % 2;
    }

    res = norm(res);
    if (neg && res != "0") res = "-" + res;
    return res;
}

void testcase() {
    string x, y; cin >> x >> y;
    string a = div2(add(x, y));
    string b = div2(sub(x, y));

    cout << a << el << b;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}