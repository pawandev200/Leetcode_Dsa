class Solution {
public:
    bool canmakezero(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n  = nums.size();
        vector<int>netchange(n+1, 0);
        for(int i = 0; i < k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            netchange[l]+=val; 
            if (r + 1 < n) netchange[r+1]-=val; 
        }
        int sum =0; 
        for(int i=0; i<n; i++){
            sum+=netchange[i];
            if(nums[i] > sum) return false; 
        }
        return true; 
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size(); 
        int ans = -1;

        // Binary search for the minimum k
        while (l <= r) {
            int mid = (l + r) / 2;
            if (canmakezero(nums, queries, mid)) {
                ans = mid; // Try a smaller k
                r = mid - 1;
            } else {
                l = mid + 1; // Increase k
            }
        }

        return ans;
    }
};