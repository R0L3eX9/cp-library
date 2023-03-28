template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
	trav(a,ed)
	if (D.unite(a.s.f,a.s.s)) {
		ans += a.f;
		cnt++;
	}
	return ans;
}
