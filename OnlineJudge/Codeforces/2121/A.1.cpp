#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
	int n, s;
	cin >> n >> s;
	int a[n + 1];
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (s >= *max_element(a + 1, a + n + 1)){
		cout << s - *min_element(a + 1, a + n + 1) << '\n';
		return;
	}
	
	if (s <= *min_element(a + 1, a + n + 1)){
		cout << *max_element(a + 1, a + n + 1) - s << '\n';
		return;
	}
	int kcsdau = s - *min_element(a + 1, a + n + 1);
	int kcscuoi = *max_element(a + 1, a + n + 1) - s;
	if (kcsdau >= kcscuoi){
		cout << kcscuoi + *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1) << '\n';
	}else {
		cout << kcsdau + *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1) << '\n';
	}
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t; cin >> t;
	while (t--) testcase();

	return 0;
}
