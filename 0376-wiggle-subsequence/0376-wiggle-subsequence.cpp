class Solution {
public:
    int dp[1001][1001][2];

    int solve(int i, int l, bool s, vector<int>&nums){
        //base case:
        if(i==nums.size()) return 0; 

        if(dp[i][l+1][s]!=-1) return dp[i][l+1][s];

        int diff = 0, take = 0; 
        if(l!=-1) diff = (nums[i] - nums[l]);

        if(l==-1 || (diff>0 && !s) || (diff<0 && s)){
            take = 1 + solve(i+1, i, !s, nums);
        }
        int notTake = solve(i+1, l, s, nums);

        return dp[i][l+1][s] = max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int f = solve(0, -1, true, nums);
        int s = solve(0, -1, false, nums);
        return max(f, s);
    }
};