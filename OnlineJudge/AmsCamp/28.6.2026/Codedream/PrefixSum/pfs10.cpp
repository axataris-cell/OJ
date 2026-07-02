#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#pragma GCC optimize("Ofast")
// Tà thuật

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	
	bool used[26] = {};
	int mp[26] = {0};
	for (char c : s) {
		used[c - 'a'] = true;
		++mp[c - 'a'];
	}
	int m = count(used, used + 26, true);
	
	int maxf = 0;
	for (int i = 0; i < 26; i++) {
		if (used[i]) maxf = max(maxf, mp[i]);
	}
	ll res = 0;
	
	for (int t = 1; t * m <= n && t <= maxf; t++) {
		int l = t * m;
		
		int f[26] = {0};
		int cnt = 0;
		
		for (int i = 0; i < n; i++) {
			int in = s[i] - 'a';
			++f[in];
			
			if (f[in] == t) ++cnt;
			else if (f[in] == t + 1) --cnt;
			
			if (i >= l) {
				int out = s[i - l] - 'a';
				--f[out];
				
				if (f[out] == t) ++cnt;
				else if (f[out] == t - 1) --cnt;
			}
			
			if (i >= l - 1 && cnt == m) ++res;
		}
	}
	
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
