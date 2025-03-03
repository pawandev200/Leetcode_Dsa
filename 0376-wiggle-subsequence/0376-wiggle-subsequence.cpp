class Solution {
public:
    int dp[1001][1001][2];

    int solve(int i, int l, bool s, vector<int>&nums){
        //base case:
        if(i==nums.size()) return 0; 

        if(dp[i][l+1][s]!=-1) return dp[i][l+1][s];

        int diff = 0, take = 0; 
        if(l!=-1) diff = (nums[i] - nums[l]) > 0 ? 1 : 0;

        if(l==-1 || diff != s) take = 1 + solve(i+1, i, !s, nums);
        int notTake = solve(i+1, l, s, nums);

        return dp[i][l+1][s] = max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        // equal number should ignored
        int f = solve(0, -1, true, nums); // taking first ele
        int s = solve(0, -1, false, nums); // notTaking the first ele
        return max(f, s);
    }
};