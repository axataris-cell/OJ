#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, prior, sz;
    bool rev;
    Node *l, *r;

    Node(int v) {
        val = v;
        prior = rand();
        sz = 1;
        rev = false;
        l = nullptr;
        r = nullptr;
    }
};

int getSize(Node* t) {
    if (t == nullptr) return 0;
    return t->sz;
}

void update(Node* t) {
    if (t == nullptr) return;
    t->sz = 1 + getSize(t->l) + getSize(t->r);
}

void push(Node* t) {
    if (t == nullptr) return;

    if (t->rev) {
        swap(t->l, t->r);

        if (t->l != nullptr) {
            t->l->rev ^= 1;
        }
        if (t->r != nullptr) {
            t->r->rev ^= 1;
        }

        t->rev = false;
    }
}

void split(Node* t, Node*& l, Node*& r, int k) {
    if (t == nullptr) {
        l = nullptr;
        r = nullptr;
        return;
    }

    push(t);

    if (getSize(t->l) >= k) {
        split(t->l, l, t->l, k);
        r = t;
    } else {
        split(t->r, t->r, r, k - getSize(t->l) - 1);
        l = t;
    }

    update(t);
}

Node* merge(Node* l, Node* r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;

    push(l);
    push(r);

    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

void reverse_segment(Node*& t, int l, int r) {
    Node *t1, *t2, *t3;

    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);

    if (t2 != nullptr) {
        t2->rev ^= 1;
    }

    t = merge(t1, merge(t2, t3));
}

void inorder(Node* t) {
    if (t == nullptr) return;

    push(t);

    inorder(t->l);
    cout << t->val << ' ';
    inorder(t->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* treap = nullptr;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        treap = merge(treap, new Node(a[i]));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        reverse_segment(treap, l, r);
    }

    inorder(treap);
}