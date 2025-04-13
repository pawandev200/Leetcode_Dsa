class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binpow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2; // 0, 2, 4,... (i.e., even indices)
        long long odd_positions = n / 2;        // 1, 3, 5,... (i.e., odd indices)

        long long evens = binpow(5, even_positions, MOD);
        long long odds = binpow(4, odd_positions, MOD);

        return (int)((evens * odds) % MOD);
    }
};
