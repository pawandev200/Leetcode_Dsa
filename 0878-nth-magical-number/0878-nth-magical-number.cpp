class Solution {
public:
    const static int mod = 1e9 + 7;

    bool check(long long x, int n, int a, int b, long long lcm){
        long long total = x/a + x/b - x/lcm;
        return total >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1;
        long long r = 1LL * n * min(a, b);
        long long ans = r;

        long long lcm = (1LL * a * b) / __gcd(a, b);

        while(l <= r){
            long long mid = l + (r - l)/2;

            if(check(mid, n, a, b, lcm)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans % mod;
    }
};