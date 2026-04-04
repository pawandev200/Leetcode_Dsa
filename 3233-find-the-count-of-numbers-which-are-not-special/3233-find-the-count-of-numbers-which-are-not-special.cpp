class Solution {
public:
/*
Exactly 2 proper divisors = Exactly 3 total divisors
= Number must be a square of a prime (p²)
x=p^2 => x = sqrt(p)
*/
    vector<bool>sieve(int n){
        vector<bool>isprime(n+1, 1);
        isprime[0] = isprime[1] = 0; 
        for(int i=2; i*i<=n; i++){
            if(isprime[i]){
                for(int j = i*i; j<=n; j+=i) isprime[j] = 0; 
            }
        }
        return isprime; 
    }
    int nonSpecialCount(int l, int r) {
        int lim = sqrt(r);
        vector<bool>isprime = sieve(lim);
        int spcnt = 0; 
        for(int i = 1; i<=lim; i++){
            if(isprime[i]){
                long long sq = 1LL* i*i; 
                if(sq >=l && sq <=r) spcnt++; 
            }
        }
           
        return (r-l + 1 - spcnt);
    }
};