class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>nums; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                nums.push_back(grid[i][j]);
            }
        }
        //checking making conversion is possible or not: 
        int mod = nums[0]%x; 
        for(auto num: nums){
            if(num%x != mod) return -1; 
        }
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int med = 0; 
        if(size%2==1) med = nums[size/2];
        else med = nums[(size/2 + (size/2+1))/2];
        
        int cnt = 0; 
        for(auto num: nums){
            cnt+= abs(num-med)/x; // number of operation takes to make it equal 
        }
        return cnt; 
    }
};