#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int z[100005] = {};

void testcase() {
    string s, t;
    cin >> s >> t;

    string c = s + '#' + t;
    int n = c.length();

    fill(z, z + n, 0);

    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i <= R) z[i] = min(R - i + 1, z[i - L]);
        while (i + z[i] < n && c[z[i]] == c[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }

    vector<int> res;
    for (int i = s.length() + 1; i < n; i++) {
        if (z[i] == s.length()) {
            res.push_back(i - (s.length() + 1));
        }
    }

    cout << res.size() << '\n';
    for (auto x : res) cout << x << " ";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
