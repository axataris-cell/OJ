#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > k) a[i] = 1;
		else if (a[i] == k) a[i] = 0;
		else if (a[i] < k) a[i] = -1;
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
}
