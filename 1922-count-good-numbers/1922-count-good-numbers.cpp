class Solution {

const long long MOD = 1e9 + 7;
public:
// Function to calculates the power of a number under a modulo
long long mod_exp(int b, long long e, int m) {
    long long res = 1;
    long long base = b;
    
    while (e > 0) {
        if (e % 2 == 1) {
            res = (res * base) % m;
        }
        base = (base * base) % m;
        e /= 2;
    }
    
    return res;
}

int countGoodNumbers(long long n) { 
    long long evens = (n + 1) / 2;   //total number of even positions
    long long odds = n / 2;     //total number of even positions

    // At even index:{0, 2, 4, 6, 8} -> total 5 possible digits to be filled
    // At odd index:{2, 3, 5, 7} -> total 4 possible digits to be filled
    
    // Calculate the number of good digit strings
    long long total = mod_exp(5, evens, MOD) * mod_exp(4, odds, MOD) % MOD;
    return total;
 }
};