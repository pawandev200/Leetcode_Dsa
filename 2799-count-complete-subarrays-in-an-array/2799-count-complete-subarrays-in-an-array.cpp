class Solution {
public:
    int solve(vector<int>& nums, int dcnt){
        int n = nums.size();
        unordered_map<int, int>wmp; 
        int i = 0; 
        int j = 0;
        int cnt = 0; 
        while(j<n){
            wmp[nums[j]]++; 
            while(wmp.size() >= dcnt){
                cnt+=n-j; 
                if(wmp.find(nums[i])!=wmp.end()) wmp[nums[i]]--;
                if(wmp[nums[i]] == 0) wmp.erase(nums[i]);
                i++; 
            }
            j++; 
        }
        return cnt; 
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;  
        for(auto num: nums) mp[num]++; 
        int dcnt = mp.size();
        return solve(nums, dcnt) - solve(nums, dcnt+1);
    }
};