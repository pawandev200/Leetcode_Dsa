class Solution {
public:
   
    vector<int> closestPrimes(int l, int r) {
        vector<bool>isprime(r+1, 1);
        isprime[0] = isprime[1] = 0; 
        for(int i=2; i*i<=r; i++){
            if(isprime[i]){ // means i is prime
                for(int j = i*i; j<=r; j+=i) isprime[j] = 0; 
            }
        }
        // now chcking in the range:
        int mindiff = INT_MAX;
        pair<int, int> temp = {-1, -1};  
        int prev = -1; 
        for(int i=l; i<=r; i++){
            if(isprime[i] ){
                int diff = i - prev; 
                if(prev!=-1 && diff < mindiff){
                    mindiff = diff; 
                    temp = {prev, i};
                }
                prev = i; 
            }
        }
        return {temp.first, temp.second}; 
    }
};