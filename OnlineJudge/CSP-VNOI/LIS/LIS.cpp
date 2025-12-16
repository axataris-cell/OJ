#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> ans;
	vector<int> pos;
	vector<int> prev(n, -1);
	
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
		
		if (idx == ans.size()) {
			ans.push_back(a[i]);
			pos.push_back(i);
		} else {
			ans[idx] = a[i];
			pos[idx] = i;
		}
		
		if (idx > 0) {
			prev[i] = pos[idx - 1];
		}
	}
	
	vector<int> lis;
	int i = pos.back();
	while (i != -1) {
		lis.push_back(i);
		i = prev[i];
	}
	reverse(lis.begin(), lis.end());
	
	cout << ans.size() << el;
	for (auto x : lis) cout << x + 1 << ' ';
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
