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
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>isprime = sieve(n);

        vector<vector<int>>ans; 
        int i = 1; 
        int j = n;
        while(i<=j){
            if(i + j == n){
                if(isprime[i] && isprime[j]) ans.push_back({i, j});
                i++; 
                j--; 
            } 
            else if(i + j > n) j--; 
            else i++; 
            
        }
        sort(ans.begin(), ans.end());
        if(ans.size() == 0) return {};
        return ans; 
    }
};