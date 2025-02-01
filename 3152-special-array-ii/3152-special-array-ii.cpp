class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,vector<vector<int>>& queries){
        int n = nums.size();

        //pre-compution: 
        vector<int>prefix(n,0);
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1];
            if(nums[i]%2==nums[i-1]%2) prefix[i]++; 
        }
        
        vector<bool>ans;
        for(auto it: queries){
            int a = it[0];
            int b = it[1];
            int countcheck = prefix[b] - (a>0?prefix[a]:0);
            ans.push_back(countcheck==0);
        }
        return ans; 
    }
};