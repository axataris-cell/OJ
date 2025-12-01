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

#define MAXN 1000005
int p[MAXN];
void sieve(){
	for(int i=1; i<=MAXN; i++)p[i] = i;
	for(int i=1; i<MAXN; i++){
		if(p[i] == i){
			for(int j=i*i; j<MAXN; j+=i){
				p[j] = i;
			}
		}
	}
}
void testcase() {

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
