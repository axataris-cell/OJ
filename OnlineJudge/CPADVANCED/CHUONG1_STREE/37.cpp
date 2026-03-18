#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int l, r;
    mutable char c;

    Node(int _l, int _r = -1, char _c = 0) : l(_l), r(_r), c(_c) {}

    bool operator<(const Node& other) const {
        return l < other.l;
    }
};

set<Node> st;

auto split(int pos) {
    auto it = st.lower_bound(Node(pos));
    if (it != st.end() && it->l == pos) return it;

    --it;
    if (it->r < pos) return st.end();

    int l = it->l, r = it->r;
    char c = it->c;
    st.erase(it);

    st.insert(Node(l, pos - 1, c));
    return st.insert(Node(pos, r, c)).first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++) {
        st.insert(Node(i, i, s[i]));
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        auto itr = split(r + 1);
        auto itl = split(l);

        int cnt[26] = {0};

        for (auto it = itl; it != itr; it++) {
            cnt[it->c - 'a'] += (it->r - it->l + 1);
        }

        st.erase(itl, itr);

        int pos = l;

        if (k == 1) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    st.insert(Node(pos, pos + cnt[i] - 1, char(i + 'a')));
                    pos += cnt[i];
                }
            }
        } else {
            for (int i = 25; i >= 0; i--) {
                if (cnt[i]) {
                    st.insert(Node(pos, pos + cnt[i] - 1, char(i + 'a')));
                    pos += cnt[i];
                }
            }
        }
    }

    string res(n + 1, 'a');

    for (auto it : st) {
        for (int i = it.l; i <= it.r; i++) {
            res[i] = it.c;
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i];
}
