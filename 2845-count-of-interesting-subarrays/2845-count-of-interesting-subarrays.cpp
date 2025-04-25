class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        vector<int>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            if(nums[i]%mod == k) prefix[i] = 1; 
            else prefix[i] = 0; 
        }
        unordered_map<long long, long long>mp;
        long long sum = 0; 
        long long cnt = 0;  
        for(int i=0; i<n; i++){
            sum+=prefix[i];
            int val = sum % mod; 
            if(val == k) cnt++;
            if(mp.find((sum - k + mod)%mod) != mp.end()) cnt+=mp[(sum-k+mod)%mod];
            mp[val]++; 
        }
        return cnt; 
    }
};