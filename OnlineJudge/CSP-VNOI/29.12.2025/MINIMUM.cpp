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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		
		dq.push_back(i);
		if (dq.front() <= i - k) dq.pop_front();
		
		if (i >= k - 1) cout << a[dq.front()] << ' ';
	}
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
