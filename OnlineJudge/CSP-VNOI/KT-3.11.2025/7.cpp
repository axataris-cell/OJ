



// từ bỏ




#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1e5 + 5;
int A[MAXN] = {};
int B[MAXN] = {};

int n, m;

bool ok(ll r) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && B[j] + r < A[i]) j++;
        if (j == m) return (A[i] - B[m - 1] <= r);
        if (B[j] - r > A[i]) return false;
    }
    return true;
}

void testcase() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i]; //vị trí thành phố
	for (int i = 0; i < m; i++) cin >> B[i]; // Trụ
	
	sort(A, A + n);
	sort(B, B + m);
	
	ll l = 0, r = 1e9, res = r;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
