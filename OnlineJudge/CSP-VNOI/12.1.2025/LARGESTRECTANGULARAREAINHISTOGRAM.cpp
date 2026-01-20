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

int res(vector<int> h) {
    stack<int> st;
    int maxArea = 0;
    h.push_back(0);

    for (int i = 0; i < h.size(); i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    h.pop_back();
    return maxArea;
}

void testcase() {
    int m, n;
    cin >> m >> n;

    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> height(n, 0);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'W')
                height[j]++;
            else
                height[j] = 0;
        }
        ans = max(ans, res(height));
    }

    cout << ans;
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
