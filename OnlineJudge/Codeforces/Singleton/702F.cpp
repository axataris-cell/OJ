#include <bits/stdc++.h>
using namespace std;

struct Node {
    int b, ans, id, pri;
    int lazy_b, lazy_ans;
    Node *l, *r;

    Node(int _b, int _id) : b(_b), id(_id), ans(0), pri(rand()), 
                            lazy_b(0), lazy_ans(0), l(nullptr), r(nullptr) {}
};

// Đẩy tag xuống các con
void push(Node* t) {
    if (!t) return;
    if (t->lazy_b || t->lazy_ans) {
        if (t->l) {
            t->l->b -= t->lazy_b;
            t->l->ans += t->lazy_ans;
            t->l->lazy_b += t->lazy_b;
            t->l->lazy_ans += t->lazy_ans;
        }
        if (t->r) {
            t->r->b -= t->lazy_b;
            t->r->ans += t->lazy_ans;
            t->r->lazy_b += t->lazy_b;
            t->r->lazy_ans += t->lazy_ans;
        }
        t->lazy_b = 0;
        t->lazy_ans = 0;
    }
}

void split(Node* t, int val, Node*& l, Node*& r) {
    if (!t) { l = r = nullptr; return; }
    push(t);
    if (t->b <= val) {
        split(t->r, val, t->r, r);
        l = t;
    } else {
        split(t->l, val, l, t->l);
        r = t;
    }
}

Node* merge(Node* l, Node* r) {
    push(l); push(r);
    if (!l || !r) return l ? l : r;
    if (l->pri > r->pri) {
        l->r = merge(l->r, r);
        return l;
    } else {
        r->l = merge(l, r->l);
        return r;
    }
}

// Chèn thủ công các node bị giảm ngân sách mạnh
void insert(Node*& root, Node* node) {
    Node *l, *r;
    split(root, node->b, l, r);
    root = merge(merge(l, node), r);
}

// Hàm đệ quy để lấy các node trong đoạn [c, 2c) ra chèn lại
void re_insert(Node*& root, Node* t, int c) {
    if (!t) return;
    push(t);
    re_insert(root, t->l, c);
    re_insert(root, t->r, c);
    t->l = t->r = nullptr;
    t->b -= c;
    t->ans++;
    insert(root, t);
}

int final_ans[200005];
void get_result(Node* t) {
    if (!t) return;
    push(t);
    final_ans[t->id] = t->ans;
    get_result(t->l);
    get_result(t->r);
}

struct Shirt { int c, q; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<Shirt> shirts(n);
    for (int i = 0; i < n; i++) cin >> shirts[i].c >> shirts[i].q;

    // Sắp xếp áo theo Quality giảm, Price tăng
    sort(shirts.begin(), shirts.end(), [](Shirt a, Shirt b) {
        if (a.q != b.q) return a.q > b.q;
        return a.c < b.c;
    });

    int k; cin >> k;
    Node* root = nullptr;
    for (int i = 0; i < k; i++) {
        int b; cin >> b;
        insert(root, new Node(b, i));
    }

    for (auto &s : shirts) {
        Node *L, *Mid, *R;
        split(root, s.c - 1, L, R);      // L: b < c
        split(R, 2 * s.c - 1, Mid, R);   // Mid: c <= b < 2c, R: b >= 2c

        if (Mid) re_insert(L, Mid, s.c); // Xử lý thủ công đoạn rắc rối
        if (R) {
            R->b -= s.c;
            R->ans++;
            R->lazy_b += s.c;
            R->lazy_ans++;
        }
        root = merge(L, R);
    }

    get_result(root);
    for (int i = 0; i < k; i++) cout << final_ans[i] << " ";
    return 0;
}