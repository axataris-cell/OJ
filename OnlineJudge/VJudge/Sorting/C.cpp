#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

struct dat {
	int x, y, z;
};

dat A[105];

void testcase() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i].x >> A[i].y >> A[i].z;
	}
	sort(A, A + n, [](dat a, dat b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		else return a.z < b.z;
	});
	for (int i = 0; i < n; i++) cout << A[i].x << ' ' << A[i].y << ' ' << A[i].z << el;
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
