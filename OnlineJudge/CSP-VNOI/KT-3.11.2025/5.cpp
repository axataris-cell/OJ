#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[1000005] = {};

void testcase() {
	int n; cin >> n;
	
	vector<pair<int, int>> im(1000005, {0, -INT_MAX});
	vector<pair<int, int>> in(1000005, {0, INT_MAX});
	
	int nm = 0, nn = 0;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] >= im.back().second) {
			if (A[i] > im.back().second) {
				im.clear();
				nm = 1;
				im.push_back({i, A[i]});
			} else {
				++nm;
				im.push_back({i, A[i]});
			}
		}
		if (A[i] <= in.back().second) {
			if (A[i] < in.back().second) {
				in.clear();
				nn = 1;
				in.push_back({i, A[i]});
			} else {
				++nn;
				in.push_back({i, A[i]});
			}
		}
	}
	
//	cout << "MAX" << el;
//	for (auto x : im) {
//		cout << x.first << ' ' << x.second;
//		cout << el;
//	}
//	cout << "MIN" << el;
//	for (auto x : in) {
//		cout << x.first << ' ' << x.second;
//		cout << el;
//	}
	
	im.resize(nm);
	in.resize(nn);
	//sor + 2 con cho

	sort(im.begin(), im.end());
	sort(in.begin(), in.end());
	

	
	int i = 0, j = 0;
	int res = n;
	while (i < im.size() && j < in.size()) {
		if (im[i].first - in[j].first > 0) {
			res = min(res, abs(im[i].first - in[j].first) + 1);
			++j;
		} else if (im[i].first - in[j].first < 0) {
			res = min(res, abs(im[i].first - in[j].first) + 1);
			++i;
		} else {
			res = 1;
			break;
		}
	}
	
	cout << res << el;
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
