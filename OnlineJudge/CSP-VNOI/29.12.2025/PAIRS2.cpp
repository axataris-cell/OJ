#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!st.empty() && st.top() < h) {
            result++;
            st.pop();
        }

        if (!st.empty()) {
            result++;
        }

        st.push(h);
    }

    cout << result;
    return 0;
}
