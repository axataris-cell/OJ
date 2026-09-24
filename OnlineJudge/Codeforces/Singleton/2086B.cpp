#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> a(n + 1, 0), f(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		f[i] = f[i + 1] + a[i];
	}
	int base = 0;
	{
		int l = 0, r = k;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (f[1] * mid <= x) {
				base = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
	}
	int plus = n + 1;
	{
		int l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (f[1] * base + f[mid] >= x) {
				plus = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
	}
	plus = n - plus + 1;
//	cout << base;return;
	if (base == k) {
		cout << (f[1] * k >= x ? 1 : 0) << el;
		return;
	}
	cout << n * k - (n * base + plus) + 1 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

