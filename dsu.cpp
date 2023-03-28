struct DSU {
  vector<int> siz, par;
  DSU(int n) : siz(n, 1), par(n) { iota(par.begin(), par.end(), 0); }
  int size(int a) { return siz[find(a)]; }
  int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
  bool same(int a, int b) { return find(a) == find(b); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a, siz[a] += siz[b];
    return true;
  }
};
