class Solution {
public:
    int solve(int i, int l, bool s, vector<int>&nums){
        //base case:
        if(i==nums.size()) return 0; 

        int diff = (nums[i] - l) >0 ? 1: 0;
        int take = 0;  
        if(l==-1 || diff != s) take = 1 + solve(i+1, nums[i], !s, nums);
        int notTake = solve(i+1, l, s, nums);

        return max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        return solve(0, -1, true, nums);
    }
};