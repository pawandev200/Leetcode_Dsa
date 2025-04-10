class Solution {
public:
    int lim;
    string sfx;
    string low, high;
    int n, pre_len;
    vector<long long> memo;
    
long long dfs(int i, bool tightLow, bool tightHigh) {
        if (i == n) return 1;

        if (!tightLow && !tightHigh && memo[i] != -1) return memo[i];

        int lo = tightLow ? low[i] - '0' : 0;
        int hi = tightHigh ? high[i] - '0' : 9;

        long long res = 0;
        if (i < pre_len) {
            for (int d = lo; d <= min(hi, lim); ++d) {
                res += dfs(i + 1, tightLow && d == lo, tightHigh && d == hi);
            }
        } else {
            int required = sfx[i - pre_len] - '0';
            if (required >= lo && required <= min(hi, lim)) {
                res = dfs(i + 1, tightLow && required == lo, tightHigh && required == hi);
            }
        }

        if (!tightLow && !tightHigh) memo[i] = res;
        return res;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        sfx = s;
        lim = limit;

        low = to_string(start);
        high = to_string(finish);

        n = high.size();
        low = string(n - low.size(), '0') + low;  // pad low with zeros
        pre_len = n - sfx.size();                // prefix part length
        memo.assign(n, -1);

        return dfs(0, true, true);
    }
};
