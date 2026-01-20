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
	int n, k; cin >> n >> k;
	vector<int> a(n + 5);
	deque<int> dq;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
		
		while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);
		
		if (i >= k) cout << a[dq.front()] << ' ';
	}
	cout << el;
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
