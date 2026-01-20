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
	
	int cnt[105][1005]; // Tần số xuất hiện của số i tính tới vị trí j (1base) trong a
	for (int i = 0; i < 1e2 + 5; i++) cnt[i][0] = 0;
	
	int mp[105] = {};
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[j][i] = cnt[j][i - 1];
		}
		++cnt[a[i]][i];
	}
	
	bool check; int s = -1;
	for (int i = k; i <= n; i++) {
		bool bruh = true;
		for (int j = 1; j <= n; j++) {
			int f = cnt[j][i] - cnt[j][i - k];
			if (f == 0 && mp[j] != 0) {
//				cout << j << ' ' << i << ' ' << cnt[j][i] << ' ' << cnt[j][i - k] << ' ' << mp[j] << el;
				bruh = false; break;
			}
		}
		if (!bruh) {
			check = false;
		} else {
			s = i - k + 1;
			check = true;
			break;
		}
	}
//	if (check) {
//		cout << "YEAH" << el;
//	} else cout << "NO" << el;
	if (!check) {
		cout << -1 << el;
		return;
	} else {
		// sang trai
		int l = s, r = s + k - 1;
		cout << "DEBUG: " << l  << ' ' << r << el;
		while (l > 1) {
			while (a[l - 1] != a[r]) {
				a.insert(a.begin() + l, a[r]); ++n;
			}
			--l; --r;
		}
		
		//sang phai
		l = s, r = s + k - 1;
		while (r < n) {
			while (a[r + 1] != a[l]) {
				a.insert(a.begin() + r + 1, a[l]); ++n;
				++l; ++r;
			}
			++l; ++r;
		}
	}
	cout << n << el;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
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
