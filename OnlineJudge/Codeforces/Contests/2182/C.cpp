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
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];

	vector<int> A(2 * n), B(2 * n), C(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		A[i] = a[i % n];
		B[i] = b[i % n];
		C[i] = c[i % n];
	}

	vector<bool> goodAB(n, true), goodBC(n, true);

	for (int x = 0; x < n; x++) {
		for (int t = 0; t < n; t++) {
			if (A[t] >= B[t + x]) {
				goodAB[x] = false;
				break;
			}
		}
	}

	for (int y = 0; y < n; y++) {
		for (int t = 0; t < n; t++) {
			if (B[t] >= C[t + y]) {
				goodBC[y] = false;
				break;
			}
		}
	}

	ll cntAB = 0, cntBC = 0;
	for (int i = 0; i < n; i++) {
		if (goodAB[i]) cntAB++;
		if (goodBC[i]) cntBC++;
	}

	cout << cntAB * cntBC * n << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t; cin >> t;
	while (t--) testcase();

	return 0;
}
