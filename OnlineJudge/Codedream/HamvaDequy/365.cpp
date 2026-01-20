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

bool check1(ld a, ld b, ld c) {
	if (a + b > c && b + c > a && c + a > b) return true;
	return false;
}

bool check2(ld a, ld b, ld c) {
	if (a == b || b == c || c == a) return true;
	return false;
}

void testcase() {
	ld a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	if (!check1(a, b, c) || !check1(d, e, f)) {
		cout << -1; return;
	}
	if (!check2(a, b, c) || !check2(d, e, f)) {
		cout << -1; return;
	}
	vector<ld> t1 = {a, b, c}, t2 = {d, e, f};
	sort(t1.begin(), t1.end()); sort(t2.begin(), t2.end());
	
	if (t1 != t2) {
		cout << -1; return;
	}
	
	ld p = (a + b + c) / 2;
	cout << setprecision(2) << fixed << 2 * sqrt(p * (p - a) * (p - b) * (p - c));
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
