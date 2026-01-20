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
map<int,int>mp;
int a[200005];
void testcase() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	ll dem=0;
	for(auto x:mp){
		if(x.second >=2){
			ll tmp = ((n-x.second)*(x.second*(x.second-1))/2);
			dem += tmp;
		}
	}
	cout << dem;
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
