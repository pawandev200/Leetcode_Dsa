class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        int n = nums.size();
        vector<vector<int>>ans; 
        if(n<4) return ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue; 
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue; 
                int l = j+1; 
                int r = n-1; 
                while(l<r){
                    long long sum = ((long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r]);
                    if(sum < t) l++; 
                    else if(sum > t) r--; 
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int ls = l, re = r; 
                        while(ls < re && nums[ls] == nums[l]) ls++;
                        while(re >ls && nums[re] == nums[r]) re--;
                        l = ls, r = re; 
                    }
                }
            }
        }
        return ans;  
    }
};