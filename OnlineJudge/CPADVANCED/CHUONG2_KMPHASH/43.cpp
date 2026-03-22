#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-21 23:22

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

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

string merge2(string a, string b) {
    string s = b + "#" + a;
    vector<int> pi = prefix_function(s);

    int overlap = pi.back();

    return a + b.substr(overlap);
}

void testcase() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<string> v = {s1, s2, s3};

    string ans;

    sort(v.begin(), v.end());

    bool first = true;

    do {
        string cur = merge2(v[0], v[1]);
        cur = merge2(cur, v[2]);

        if (first || cur.size() < ans.size() ||
            (cur.size() == ans.size() && cur < ans)) {
            ans = cur;
            first = false;
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << ans.size();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}