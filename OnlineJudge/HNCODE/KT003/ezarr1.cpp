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
int a[1005];
void testcase() {
	int n;
	cin >>  n;
	vector<int>v;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i]%2 == 0)cout << a[i] << " ";
		else v.push_back(a[i]);
	}
	cout << el;
	for(int i=0; i<v.size(); i++)cout << v[i] << " ";
	
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
