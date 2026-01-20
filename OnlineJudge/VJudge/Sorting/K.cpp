#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int countInv(string s) {
    int inv = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) inv++;
        }
    }
    return inv;
}

void testcase() {
    int m, n; cin >> m >> n;
    vector<pair<int, string>> v(m);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back({countInv(s), s});
    }
    sort(v.begin(), v.end(), [](auto a, auto b) {return a.first < b.first;});
    for (auto p : v) cout << p.second << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
