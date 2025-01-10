class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return { };
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return { };

        vector<vector<int>>ans;
        for(int i =0; i<n; i++){
            if(nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; //skipping the duplicates
            
            int j = i+1;
            int k = n-1; 
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--; 
                else if(sum < 0) j++; 
                else if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // to avoid the duplicates
                    int lacj = nums[j];
                    int fack = nums[k];
                    while(j < k && lacj == nums[j]) j++; // updating the j
                    while(j < k && fack == nums[k]) k--;  
                }
            }
        }
        return ans; 
    }
};