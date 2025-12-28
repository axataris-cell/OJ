#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
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
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> lis;
	vector<int> pos;
	vector<int> prev(n, -1);
	
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		
		if (idx == lis.size()) {
			lis.push_back(a[i]);
			pos.push_back(i);
		} else {
			lis[idx] = a[i];
			pos[idx] = i;
		}
		
		if (idx > 0) {
			prev[i] = pos[idx - 1];
		}
	}
	
	cout << lis.size() << el;
	
	vector<int> res;
	int l = pos.back();
	while (l != -1) {
		res.push_back(l);
		l = prev[l];
	}
	
	reverse(res.begin(), res.end());
	
	for (auto x : res) cout << a[x] << ' ';
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
