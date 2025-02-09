class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int, int>mp; // freq for gp: f>1: form gp

        // num of pair = xc2
        // j - i != nums[j] - nums[i]
        // nums[i] - i = nums[j] - j 

        for(int i=0; i<n; i++) mp[nums[i] - i]++;
        int good = 0;
        for(auto it: mp){
            int cnt = it.second; 
            good+= 1LL*cnt*(cnt-1)/2; 
        } 
        return 1LL*n*(n-1)/2 - good; // tp - gp = bad pair
    }
};