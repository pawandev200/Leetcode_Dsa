class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; 
        for(int i=0; i<n; i++){
            unordered_map<int, int>mpodd, mpeven; 
            int temp = INT_MIN; 
            for(int j = i; j<n; j++){
                if(nums[j]%2==0) mpeven[nums[j]]++; 
                else mpodd[nums[j]]++; 
                if(mpeven.size() == mpodd.size()) temp = max(temp, j-i+1);
            }
            ans = max(ans, temp);
        }
        return ans; 
    }
};