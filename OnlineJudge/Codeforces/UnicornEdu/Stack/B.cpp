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
	stack<pair<ll, ll>> st; // height - count
	ll ans = 0;
	
	for (int i = 0; i < n; i++) {
		ll h; cin >> h;
		ll cnt = 1;
		
        while (!st.empty() && st.top().first < h) {
            ans += st.top().second;
            st.pop();
        }
        
        if (!st.empty() && st.top().first == h) {
            pair<ll, ll> top = st.top();
            st.pop();
            ans += top.second;
            cnt += top.second;

            if (!st.empty()) ans++;
        } else { 
            if (!st.empty()) ans++;
        }

        st.push({h, cnt});
	}
	
	cout << ans;
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
