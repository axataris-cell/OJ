#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
map<int,int>mp;
char a[5005][5005];
int dem[5005];
void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j] == 'X')dem[j]++;
		}
		
	}
	int res= INT_MIN;
	for(int i=1; i<=5000; i++){
		res = max(res, dem[i]);
	}
	int sl=0;
	for(int i=1; i<=5000; i++){
		if(dem[i]==res)sl++;
	}
	cout << sl << " " << res << "\n";
	for(int i=1; i <= 5000; i++){
		if(dem[i] == res)cout << i << " ";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}