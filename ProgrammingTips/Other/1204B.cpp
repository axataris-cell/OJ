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
	int n,l,r;
	cin >> n >> l >> r;
	int minsum = 0;
	int maxsum = 0;
	for (int i = 0; i < l; i++){
		minsum += pow(2,i);
	}
	for (int i = 1; i <= n - l; i++){
		minsum += 1;
	}
	for (int i = 0; i < r; i++){
		maxsum += pow(2,i);
	}
	if (r < n){
		for (int i = 1; i <= n - r; i++){
			maxsum += pow(2, (r - 1));
		}
	}
	cout << minsum << " " << maxsum;
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
