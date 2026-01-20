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
	string s;
	cin >> s;
	int vitri = 0;
	bool co = true;
	if (s[0] != s[s.size() - 1]){
		for (int i = 0; i < s.size(); i++){
			if (s[i] == s[s.size() - 1 - i]){
				vitri = i;
			}
		}
		int l = vitri, int r = (int)s.size() - vitri - 1;
		while (l <= r){
			if (s[l] != s[r]){
				l++;
				r--;
			}else {
				co = false;
				break;	
			}
		}	
	}
	int vitri2 = 0;
	if (s[0] == s[s.size() - 1]){
		for (int i = 0; i < s.size(); i++){
			if (s[i] != s[s.size() - i - 1]){
				vitri2 = 0;
			}
		}
	}
	while (l <= r){
		if (s[l] != s[r]){
			l++;
			r--;
		}else {
			co = false;
			break;
		}
	}
	if (co){
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	int t; cin >> t;
	while (t--) testcase();

	return 0;
}
