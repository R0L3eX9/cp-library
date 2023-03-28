int LOG = 1;
vector<vector<int>> st;
vector<int> lg2;
void build_table(const vector<int> &v, const int &n) {
    while ((1 << LOG) <= n) ++LOG;
    st = vector<vector<int>>(n, vector<int>(LOG));
    lg2 = vector<int>(n + 1);
    for (int i = 2; i <= n; ++i) {
        lg2[i] = lg2[i / 2] + 1;
    }

    for (int i = 0; i < n; ++i) {
        st[i][0] = v[i];
    }
    for (int pw = 1; pw < LOG; ++pw) {
        for (int i = 0; i <= n - (1 << pw); ++i) {
            st[i][pw] = min(st[i][pw - 1], st[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

int qry(int l, int r) {
    int m = r - l + 1;
    int k = lg2[m];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}
