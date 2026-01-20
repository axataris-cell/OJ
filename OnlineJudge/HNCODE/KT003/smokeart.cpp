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
int a[100005];
map<int,int>mp;
map<int,int>mp2;
void testcase() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		mp[a[i]]=1;
	}
	int pos =1;
	for(auto x:mp){
		mp2[x.first]  = n-pos; 
		pos++;
	}
	for(int i=1; i<=n; i++){
		cout << mp2[a[i]] << " ";
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
