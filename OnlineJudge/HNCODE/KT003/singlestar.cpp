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
	ll n , a, b, c;
	cin >> n >> a >> b >> c;
	ll res = 0;
	if(a!=b && a!=c && b!=c)res = (n/a) + (n/b) +(n/c) - (n/(a*b)) - (n/(b*c)) - (n/(c*a)) + (n/(a*b*c));
	else if(a==b && b==c)res = n/a;
	else if(a==b)res = (n/a) + (n/c) - (n/(a*c));
	else if(a==c)res = (n/a) + (n/b) - (n/(a*b));
	else if(c==b)res = (n/a) + (n/c) - (n/(a*c));
	cout << res;
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
