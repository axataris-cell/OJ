function LCA(N, P[MAXN][MAXLOGN], T[MAXN], h[MAXN], u, v):
  if h(u) < h(v):
    // Đổi u và v
    swap(u, v)

  log = log2( h(u) )

  // Tìm tổ tiên u' của u sao cho h(u') = h(v)

  for i = log .. 0:
    if h(u) - 2^i >= h(v):
      u = P[u][i]

  if u == v:
    return u

  // Tính LCA(u, v):
  for i = log .. 0:
    if P[u][i] != -1 and P[u][i] != P[v][i]:
      u = P[u][i]
      v = P[v][i]

  return T[u];