int find(int x) {
    if (parent[x] == x) return x;
    int p = find(parent[x]);
    color[x] ^= color[parent[x]];
    return parent[x] = p;
}

bool unite(int a, int b, int w) { //w = 0 là cùng nhóm, w = 1 là khác nhóm
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return (color[a] ^ color[b]) == w;

    parent[pa] = pb;
    color[pa] = color[a] ^ color[b] ^ w;
    return true;
}
