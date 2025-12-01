#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> a(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    vector<int> h(N, 0);
    long long ans = 0;

    for (int i = 0; i < M; i++) {
        // build histogram
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 1) h[j]++;
            else h[j] = 0;
        }

        // largest rectangle in histogram for row i
        stack<int> st;
        for (int j = 0; j <= N; j++) {
            int curH = (j == N ? 0 : h[j]);
            while (!st.empty() && curH < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long width = j - left - 1;
                ans = max(ans, 1LL * height * width);
            }
            st.push(j);
        }
    }

    cout << ans;
    return 0;
}
