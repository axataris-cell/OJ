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
	string s; cin >> s;
	int n = s.length();
	
	vector<int> pos[(int)('z') + 1];
	for (int i = 0; i < n; i++) {
		pos[s[i]].push_back(i);
	}
	int res = 0;
	for (int i = 0; i < pos['m'].size(); i++) {
		auto bi = upper_bound(pos['a'].begin(), pos['a'].end(), pos['m'][i]);
		cerr <<  'i' << i << ' ';
		if (bi == pos['a'].end()) {
			cout << res; return;
		}
		for (int j = bi - pos['a'].begin(); j < pos['a'].size(); j++) {
			auto bj = upper_bound(pos['r'].begin(), pos['r'].end(), pos['a'][j]);
			cerr << 'j' << j << ' ';
			if (bj == pos['r'].end()) {
				cout << res; return;
			}
			for (int k = bj - pos['r'].begin(); k < pos['r'].size(); k++) {
				auto bk = upper_bound(pos['i'].begin(), pos['i'].end(), pos['r'][k]);
				cerr << 'k' << k << ' ';
				if (bk == pos['i'].end()) {
					cout << res; return;
				}
				for (int l = bk - pos['i'].begin(); l < pos['i'].size(); l++) {
					auto bl = upper_bound(pos['s'].begin(), pos['s'].end(), pos['i'][l]);
					cerr << 'l' << l << ' ';
					if (bl == pos['s'].end()) {
						cout << res; return;
					}
					for (int m = bl - pos['s'].begin(); m < pos['s'].size(); m++) {
						auto bm = upper_bound(pos['a'].begin(), pos['a'].end(), pos['s'][m]);
						cerr << 'm' << m << ' ';
						if (bm == pos['a'].end()) {
							cout << res; return;
						}
						res += pos['a'].size() - (bm - pos['a'].begin());
					}
				}
			}
		}
		cerr << el;
	}
	cerr << "end" << el;
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
