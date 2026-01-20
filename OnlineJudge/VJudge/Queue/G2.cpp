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
unordered_map<string, int> mp;
void build() {
	int n = 1;
	for (int i = 'a'; i <= 'z'; i++) {
		string x; x.push_back((char)i);
		mp[x] = n; ++n;
	}
	for (int i = 'a'; i < 'z'; i++) {
		for (int j = i + 1; j <= 'z'; j++) {
			string x; x.push_back((char)i); x.push_back((char)j);
			mp[x] = n; ++n;
		}
	}
	for (int i = 'a'; i < 'z' - 1; i++) {
		for (int j = i + 1; j < 'z'; j++) {
			for (int k = j + 1; k <= 'z'; k++) {
				string x; x.push_back((char)i); x.push_back((char)j); x.push_back((char)k);
				mp[x] = n; ++n;
			}
		}
	}
	for (int i = 'a'; i < 'z' - 2; i++) {
		for (int j = i + 1; j < 'z' - 1; j++) {
			for (int k = j + 1; k < 'z'; k++) {
				for (int l = k + 1; l <= 'z'; l++) {
					string x; x.push_back((char)i); x.push_back((char)j); x.push_back((char)k); x.push_back((char)l); 
					mp[x] = n; ++n;
				}
			}
		}
	}
	for (int i = 'a'; i < 'z' - 3; i++) {
		for (int j = i + 1; j < 'z' - 2; j++) {
			for (int k = j + 1; k < 'z' - 1; k++) {
				for (int l = k + 1; l < 'z'; l++) {
					for (int yn = l + 1; yn <= 'z'; yn++) {
						string x; x.push_back((char)i); x.push_back((char)j); x.push_back((char)k); x.push_back((char)l); x.push_back((char)yn);
						mp[x] = n; ++n;
					}
				}
			}
		}
	}
}

void testcase() {
	string s;
	while (cin >> s) cout << mp[s] << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	
	build();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
