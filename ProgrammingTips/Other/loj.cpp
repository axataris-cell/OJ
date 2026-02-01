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

bool comp(int a, int b) {
    return (a % 10) < (b % 10); // so sánh theo chữ số cuối
}


void testcase() {
	vector<int> v = {12, 33, 25};
	do {
		for (auto x : v) cout << x << ' ';
		cout << el;
	} while (next_permutation(v.begin(), v.end(), comp));
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
