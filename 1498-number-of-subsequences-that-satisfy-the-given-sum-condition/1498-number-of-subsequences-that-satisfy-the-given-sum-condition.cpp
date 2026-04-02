class Solution {
public:
    const static int mod = 1e9 + 7; 

    int numSubseq(vector<int>& nums, int tar) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int>pow(n, 1);
        for(int i=1; i<n; i++) pow[i] = (pow[i-1] * 2) % mod; 

        int i = 0; 
        int j = n-1; 
        int cnt = 0; 
        while(i<=j){
            if(nums[i] + nums[j] <= tar){
                cnt = (cnt + pow[j-i]) % mod; 
                i++; 
            }
            else j--; 
        }
        return cnt; 
    }
};