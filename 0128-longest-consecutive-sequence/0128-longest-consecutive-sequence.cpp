class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // just a try by sorting: TC = O(n)
        int n = nums.size();
        if(n==0) return 0;

        sort(nums.begin(), nums.end());
        int cnt=1;
        int maxi = 1;
        int temp = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == temp + 1){
                cnt++; 
                temp = nums[i];
                maxi = max(maxi, cnt);
            }
            else if (nums[i] != temp){
                temp = nums[i];
                cnt = 1;
            }
        }
        return maxi; 
    }
};