#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int A[3];
	for (int i = 0; i < 3; i++) cin >> A[i];
	sort(A, A + 3);
	int dis1 = A[1] - A[0], dis2 = A[2] - A[1];
	int temp = dis1;
	dis1 = min(dis1, dis2);
	dis2 = max(temp, dis2);
	
	int mind = 0, maxd = 0;
	if (dis1 > 2) {
		cout << "2 " << dis2 - 1 << el;
	} else if (dis1 == 2) {
		cout << "1 " << dis2 - 1 << el;
	} else if (dis1 == 1) {
		if (dis2 == 1) cout << "0 0" << el;
		else if (dis2 == 2) cout << "1 1" << el;
		else {
			cout << "2 " << dis2 - 1 << el;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
