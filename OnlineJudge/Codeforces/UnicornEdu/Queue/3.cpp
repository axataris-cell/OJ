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

const int MAXN = 3*1e5 + 5;
int A[MAXN];
int R[MAXN], len[MAXN];

void testcase() {
	int n, k; cin >> n >> k;
	deque<int> dqmin, dqmax;
	
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	int r = 1;
	for (int i = 1; i <= n; i++) {
		if (r < i) r = i;
		
		while (!dqmax.empty() && dqmax.front() < i) dqmax.pop_front();
		while (!dqmin.empty() && dqmin.front() < i) dqmin.pop_front();
		
		while (r <= n) {
			while (!dqmin.empty() && A[dqmin.back()] > A[r]) dqmin.pop_back();
			dqmin.push_back(r);
			while (!dqmax.empty() && A[dqmax.back()] < A[r]) dqmax.pop_back();
			dqmax.push_back(r);
			
			if (A[dqmax.front()] - A[dqmin.front()] > k) {
				dqmin.pop_back();
				dqmax.pop_back();
				break;
			}
			++r;
		}
		R[i] = r - 1; // Gioi han r tai i
		len[i] = R[i] - i + 1; // Size khom hoa
	}
	
	vector<int> bf(n + 3, 0);
	for (int i = n; i >= 1; i--) {
		bf[i] = max(bf[i + 1], len[i]);
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, (ll)len[i] + bf[R[i] + 1]); // Để cho không giao nhau thì sẽ là độ dài lớn nhất của khóm hoa bắt đầu tại i + độ dài lớn nhất của khóm hoa sau khi kết thúc khóm hoa bắt đầu tại i.
	}
	
	cout << ans;
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
