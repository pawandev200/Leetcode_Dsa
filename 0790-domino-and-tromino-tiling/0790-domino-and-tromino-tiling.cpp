class Solution {
    public:
        const long mod = 1e9 + 7;
        long solve(int i, int n, bool pos) {
            if (i == n) return !pos;
            if (i > n) return 0;
            if (pos)
                return (solve(i + 1, n, false) + 
                        solve(i + 1, n, true)) % mod;
            return (solve(i + 1, n, false) + 
                    solve(i + 2, n, false) + 
                    2L * solve(i + 2, n, true)) % mod;
            }

        int numTilings(int n) {
            return solve(0, n, false);
        }
    };