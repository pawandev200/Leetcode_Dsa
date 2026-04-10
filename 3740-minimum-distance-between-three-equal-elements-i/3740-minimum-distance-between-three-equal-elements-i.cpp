class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1; 
        
        int mini = INT_MAX; 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dist = abs(i-j) + abs(j-k) + abs(k-i);
                        if(mini >= dist) mini = dist; 
                    }
                }
            }
        }
        return mini == INT_MAX ? -1 : mini; 
    }
};