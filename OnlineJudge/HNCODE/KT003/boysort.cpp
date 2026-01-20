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
void testcase() {
	int n;
	cin >> n;
	vector<pii>v;
	for(int i=1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	for(int i=v.size()- 1; i>=0; i--){
		cout << v[i].first << " " << v[i].second << el;
	}
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
