#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {

        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;

        bool canStack = true, canQueue = true, canPq = true;

        while (n--) {
            int type, x;
            cin >> type >> x;

            if (type == 1) {
                st.push(x);
                qu.push(x);
                pq.push(x);
            }
            else {
                if (canStack) {
                    if (st.empty()) canStack = false;
                    else {
                        if (st.top() != x) canStack = false;
                        st.pop();
                    }
                }

                if (canQueue) {
                    if (qu.empty()) canQueue = false;
                    else {
                        if (qu.front() != x) canQueue = false;
                        qu.pop();
                    }
                }

                if (canPq) {
                    if (pq.empty()) canPq = false;
                    else {
                        if (pq.top() != x) canPq = false;
                        pq.pop();
                    }
                }
            }
        }

        int cnt = canStack + canQueue + canPq;

        if (cnt == 0) cout << "impossible\n";
        else if (cnt > 1) cout << "not sure\n";
        else {
            if (canStack) cout << "stack\n";
            else if (canQueue) cout << "queue\n";
            else cout << "priority queue\n";
        }
    }

    return 0;
}
