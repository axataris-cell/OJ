#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> L(n), R(n);
    stack<int> st;

    // ---------- MAX ----------
    // Left: strictly smaller
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        L[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Right: smaller or equal
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        R[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    ll sumMax = 0;
    for (int i = 0; i < n; i++)
        sumMax += a[i] * L[i] * R[i];

    // ---------- MIN ----------
    // Left: strictly larger
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        L[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Right: larger or equal
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        R[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    ll sumMin = 0;
    for (int i = 0; i < n; i++)
        sumMin += a[i] * L[i] * R[i];

    cout << sumMax - sumMin;
}
