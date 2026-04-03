class Solution {
public:
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

    int countPrimes(int n) {
        if(n<=2) return 0; 
        vector<bool>isprime = sieve(n);
        int cnt = 0; 
        for(int i=2; i<n; i++){
            if(isprime[i]) cnt++; 
        }
        return cnt; 
    }
};