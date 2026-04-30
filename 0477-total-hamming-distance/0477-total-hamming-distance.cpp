class Solution {
public:
    int gethdist(int x){
        return __builtin_popcount(x);
    }
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; 
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int x = nums[i] ^ nums[j]; 
                cnt+=gethdist(x);
            }
        }
        return cnt; 
    }
};