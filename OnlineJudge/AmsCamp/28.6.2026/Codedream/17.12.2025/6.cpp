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

struct comp {
	bool operator()(pii &x, pii &y) const {
		if (x.first != y.first) return x.first > y.first;
		else return x.second > y.second;
	}
};

void testcase() {
	int n; cin >> n;
	pqueue<pii, vector<pii>, comp> pq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push({x, i});
	}
	vector<pii> res;
	
//	while (!pq.empty()) {
//		cout << pq.top().first << ' ' << pq.top().second << el;
//		pq.pop();
//	}
	
	while (!pq.empty()) {
//		cout << "WORKING" << ' ' << pq.size() << el;
		
		// LOGIC
		int x = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		if (pq.top().first == x && !pq.empty()) {
			int k = pq.top().second;
			pq.pop();
			pq.push({x * 2, k});
		} else {
			res.push_back({x, i});
		}
		
		
		// DEBUG
//		pqueue<pii, vector<pii>, comp> pq2 = pq;
//		
//		while (!pq2.empty()) {
//			cout << pq2.top().first << ' ' << pq2.top().second << el;
//			pq2.pop();
//		}
//		cout << el;
//		
//		cout << x << ' ' << i << el;
//		cout << res.size() << el;
//		for (auto x : res) {
//			cout << x.first << ' ';
//		}
//		cout << el;
	}
	sort(res.begin(), res.end(), [](pii x, pii y) {
		return x.second < y.second;
	});
//	
//	cout << "RESULT" << el;
	cout << res.size() << el;
	for (auto x : res) {
		cout << x.first << ' ';
	}
	cout << el;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
