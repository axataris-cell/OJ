#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

struct dat{
	int x, y;
	int ind;
};

void testcase() {
	int n; cin >> n;
	vector<dat> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].ind = i;
	}
	
	sort(a.begin(), a.end(), [](dat a, dat b) {
		if (a.x != b.x) return a.x > b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.ind < b.ind;
	});
	for (auto x : a) cout << x.ind + 1 << ' ';
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
