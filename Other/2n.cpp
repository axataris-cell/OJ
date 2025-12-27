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
	string s; cin >> s;
	stack<int> st; //stores '(' pos 0 base
	int cur = -1; //stores last ) pos
	
	vector<int> in;
	vector<int> out(s.length(), 0);
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			cur = -1;
			st.push(i);
		} else cur = i;
		
//		if (!st.empty()) cout << i << ' ' << st.top() << ' ' << cur << el;
//		else cout << i << ' ' << -1 << ' ' << cur << el;
		
		if (!st.empty() && cur != -1) {
			for (int j = st.top() - 1; j >= 0; j--) {
				if (s[j] == ')') {
					in.push_back(j + 1);
					out[j + 1] = cur + 1;
				} else {
					break;
				}
			}
			
			in.push_back(st.top() + 1);
			out[st.top() + 1] = cur + 1;
			
			st.pop();
			cur = -1;
		}
	}
	
//	for (auto x : in) cout << x << ' ';
//	cout << el;
	
	int q; cin >> q;
	vector<int> que(q, 0);
	for (int i = 0; i < q; i++) cin >> que[i];
	
	for (int x : que) {
		auto r = binary_search(in.begin(), in.end(), x);
		if (!r) cout << "-1" << el;
		else {
			cout << out[x] << el;
		}
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
