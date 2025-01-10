class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return { };
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return { };

        set<vector<int>>st; 
        for(int i =0; i<n; i++){
            if(nums[i] > 0) break;
            int j = i+1;
            int k = n-1; 
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--; 
                else if(sum < 0) j++; 
                else if(sum == 0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++; 
                    k--; 
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it: st) ans.push_back(it);
        return ans; 
    }
};