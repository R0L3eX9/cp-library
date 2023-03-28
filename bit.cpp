struct BIT {
    vector<i64> bit;
    int N;

    constexpr int lsb(int x) { return x & -x; }

    BIT(int n, const vector<int> &v) {
        N = n;
        bit = vector<i64>(N + 1);
        for (int i = 0; i < (int)v.size(); ++i) {
            upd(i + 1, v[i]);
        }
    }

    void upd(int pos, int delta) {
        for (; pos <= N; pos += lsb(pos)) {
            bit[pos] += delta;
        }
    }

    i64 qry(int L) {
        i64 ans = 0;
        for (; L > 0; L -= lsb(L)) {
            ans += bit[L];
        }
        return ans;
    } 

    i64 qry(int L, int R) {
        return qry(R) - qry(L - 1);
    }
};
