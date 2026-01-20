#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

pair<int, int> A[100005] = {};

void testcase() {
	int n; cin >> n;
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i].first;
		tot += A[i];
	}
	for (int i = 0; i < n; i++) cin >> A[i].second;
	
	sort(A, A + n, [](pair<int, int> x, pair<int, int> y) {
		return x.second > y.second;	
	});
	sort(A + 1, A + n, [](pair<int, int> x, pair<int, int> y) {
		return x.first > y.first;
	});
	
	cout << A[0].second << ' '; ll res = A[0].second;
	for (int i = 1; i < n; i++) {
		res += A[i].first;
		cout << res << ' ';
	}
	cout << el;
	
	for (int i = 0; i < n; i++) cout << A[i].first << ' ' << A[i].second << el;
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
