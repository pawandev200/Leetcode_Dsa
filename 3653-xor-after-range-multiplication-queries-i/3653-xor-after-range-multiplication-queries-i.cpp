class Solution {
public:
    const static int mod = 1e9 + 7; 
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        for(int i=0; i<q.size(); i++){
            int l = q[i][0], r = q[i][1];
            int k = q[i][2], v = q[i][3];
            int idx = l; 
            while(idx<=r){
                nums[idx] = (1LL*nums[idx]*v) % mod; 
                idx +=k; 
            }
        }
        int ans = 0; 
        for(int i=0; i<n; i++){
            ans = ans^nums[i];
        }
        return ans; 
    }
};