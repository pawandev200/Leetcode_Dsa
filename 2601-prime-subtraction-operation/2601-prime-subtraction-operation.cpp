class Solution {
public:
    bool isprime(int n){
        if(n < 2) return false; 
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false; 
        }
        return true; 
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int prev = (i == 0 ? 0 : nums[i-1]);

            // try to find best prime to subtract
            int best = nums[i];

            for(int p = nums[i] - 1; p >= 2; p--){
                if(isprime(p)){
                    int nv = nums[i] - p;
                    if(nv > prev){
                        best = nv;
                        break; // take largest valid prime
                    }
                }
            }

            nums[i] = best;

            if(i > 0 && nums[i] <= nums[i-1]) return false;
        }

        return true;
    }
};