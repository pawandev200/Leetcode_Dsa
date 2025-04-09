class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>st; 
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>k) st.insert(nums[i]);
        }
        int ans = st.size();
        return ans ==0 ? -1 : ans; 
    }
};