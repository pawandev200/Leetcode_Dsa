class Solution {
public:

int digitsum(int num){
    int sum =0; 
    while(num>0){
        sum+=num%10; 
        num=num/10; 
    }
    return sum; 
}
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; // sum, max num at that sum
        int maxi = -1; 

        for(int i=0; i<n; i++){
            int sum  = digitsum(nums[i]);
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, nums[i] + mp[sum]);
                mp[sum] = max(mp[sum], nums[i]);
            } else mp[sum] = nums[i];
        }
        return maxi; 
    }
};