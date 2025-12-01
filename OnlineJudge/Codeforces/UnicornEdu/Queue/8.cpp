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

struct cmp {
	bool operator()(pii a, pii b) const {
		return a.second > b.second;
	}
};

void testcase() {
	int n; cin >> n; vector<pii> a(n);
	priority_queue<pii, vector<pii>, cmp> pq;
	
	for (auto &x : a) cin >> x.first >> x.second;
	sort(a.begin(), a.end());
	
	for (auto x : a) {
		if (!pq.empty() && pq.top().second < x.first) {
			pq.pop();
		}
		pq.push(x);
	}
	cout << pq.size();
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
