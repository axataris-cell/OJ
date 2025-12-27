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
	string n; cin >> n;
	int q; cin >> q;
	vector<int> que(q, 0);
	for (int i = 0; i < q; i++) {
		cin >> que[i];
		--que[i];
	}
	
	for (int i = 0; i < q; i++) {
		bool check = false;
		int op = 0, cl = 0;
		
		for (int j = que[i]; j < n.length(); j++) {
			if (n[j] == '(') ++op;
			if (cl < op && n[j] == ')') ++cl;
			
//			cout << j + 1 << ' ' << op << ' ' << cl << el;
			
			if (cl >= op && op != 0) {
				check = true;
				cout << j + 1 << el;
				break;
			} 
		}
		
		if (!check) cout << "-1" << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
