class Solution {
public:
    bool isprime(int num){
        for(int i=2; i*i <= num; i++){
            if(num%i ==0) return false; 
        }
        return true; 
    }
    vector<int> closestPrimes(int l, int r) {
        vector<int>prime; 
        for(int i=max(2,l); i<=r; i++){ // skipping the 1: bcoz it is not prime
            if(isprime(i)) prime.push_back(i);
        }
        // for(int i=0; i<prime.size(); i++) cout<<prime[i]<<endl; 

        if(prime.size() == 0) return {-1,-1};
        int mini = INT_MAX;
        int a = -1, b = -1;  
        for(int i=0; i<prime.size()-1; i++){
            if(mini > prime[i+1] - prime[i]){
                mini = prime[i+1] - prime[i];
                a = prime[i];
                b = prime[i+1];
            }
        }
        return {a,b}; 
    }
};