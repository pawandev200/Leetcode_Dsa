class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binpow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long op = n / 2;
        long long ep = n - n/2;         

        // At even indices only 5 digits are possible: 0, 2, 4, 6, 8
        // At odd indices only 4 digits are possible: 2, 3, 5, 7
        long long evens = binpow(5, ep, MOD); 
        long long odds = binpow(4, op, MOD);

        return ((evens * odds) % MOD);
    }
};
