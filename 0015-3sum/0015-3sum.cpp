class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return { };
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans; 
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue; //avoiding duplicates of i,
            int l = i + 1; 
            int r = n-1; 
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) r--; 
                else if(sum < 0) l++;  
                else if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    //avoiding duplicates: 
                    int ls = l, re = r; 
                    while(ls < re && nums[ls] == nums[l]) ls++;
                    while(re >ls && nums[re] == nums[r]) re--;
                    l = ls, r = re; 
                } 
            }
        }
        return ans; 
    }
};