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
	int n;
	cin >> n;
	ll k = pow(2,n);
	ll sum1 = k;
	ll sum2 = 0;
	for (int i = 1; i <= n/2 - 1; i++){
		sum1 += pow(2,i);
	}
	for (int i = n/2; i <= n - 1; i++){
		sum2 += pow(2,i);
	}
	cout << abs(sum2 - sum1) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	int t;
	cin >> t; //cin >> t;
	while (t--) testcase();

	return 0;
}
