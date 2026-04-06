class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        long long tcnt = 0; 
        unordered_map<int, int>mp; // prev gcd, cnt

        for(int i=0; i<n; i++){
            int g = __gcd(nums[i], k); 

            for(auto[gi, cnt]: mp){
                long long val = (long long)g*gi; 
                if(val % k == 0) tcnt+=cnt; 
            }
            mp[g]++; 
        }
        
        return tcnt; 
    }
};