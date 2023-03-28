class HashedString {
    private:
        static const int P = 53;
        static const int mod = 1e9 + 7;
        static const int P2 = 59;
        static const int mod2 = 1e9 + 9;
        int N = -1;
        vector<int> pw, pw2, h, ha2;
        int mul(int a, int b, int MOD) { return (i64) a * b % MOD; }
        int add(int a, int b, int MOD) { a += b; if (a >= MOD) a -= MOD; return a; }
        int sub(int a, int b, int MOD) { a -= b; if (a < 0) a += MOD; return a; }

    public:
        HashedString(const string &s) {
            N = (int)s.size();
            ha = vector<int>(N + 1);
            ha2 = vector<int>(N + 1);
            pw = vector<int>(N + 1);
            pw2 = vector<int>(N + 1);

            pw[0] = 1, pw2[0] = 1;
            for (int i = 0; i < N; ++i) {
                ha[i + 1] = add(mul(ha[i], P, mod), (s[i] - 'A' + 1), mod);
                ha2[i + 1] = add(mul(ha2[i], P2, mod2), (s[i] - 'A' + 1), mod2);
                pw[i + 1] = mul(pw[i], P, mod);
                pw2[i + 1] = mul(pw2[i], P2, mod2);
            }
        }
        pair<int, int> get_hash(const int &l, const int &r) { // [l, r)
            pair<int, int> ans;
            ans.first = sub(ha[r], mul(ha[l], pw[r - l], mod), mod);
            ans.second = sub(ha2[r], mul(ha2[l], pw2[r - l], mod2), mod2);
            return ans;
        }
}
