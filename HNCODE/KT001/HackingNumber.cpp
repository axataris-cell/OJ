#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n; cin >> n;
	
	if (n & 1) cout << "No";
	else {
		bool check = true;
		
		n /= 2;
		for (int i = 2; i <= n; i++) {
			bool stop = false;
			
			if (n % i == 0) {
				n /= i;
				if (n <= 1) {
					check = false;
					break;
				}
				for (int j = 2; j <= sqrt(n); j++) {
					if (n % j == 0) {
						check = false;
						break;
					}	
				}
				stop = true;
				if (!check || stop) break;
			}
		}
		
		cout << ((check) ? "Yes" : "No");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
