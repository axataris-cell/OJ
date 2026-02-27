#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
	string a; cin >> a;
	int k; cin >> k;
	int n = a.length();
	
	map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
	}
	
	vector<pair<char, int>> comp;
	
	for (auto x : mp) {
		char k = x.first;
		int v = x.second;
		comp.push_back({k, v});
	}
	sort(comp.begin(), comp.end(), [](pair<char, int> x, pair<char, int> y) {
		return x.second < y.second;
	});
	
	while (k > 0 && comp.size()) {
		if (k >= comp[0].second) {
			k -= comp[0].second;
			comp.erase(comp.begin());
		} else {
			comp[0].second -= k;
			k = 0;
			break;
		}
	}
	
	map<char, int> newmp;
	
	for (auto x : comp) {
//		cerr << x.first << ' ' << x.second << el;
		newmp[x.first] = x.second;
	}
	
	map<char, int> mp1;
	
	int cnt = 0;
	for (auto x : newmp) {
		++cnt;
	}
	
	string t = "";
	for (int i = 0; i < n; i++) {
		if (mp1[a[i]] >= newmp[a[i]]) continue;
		t += a[i];
		++mp1[a[i]];
	}
	
	cout << cnt << el;
	cout << t;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
