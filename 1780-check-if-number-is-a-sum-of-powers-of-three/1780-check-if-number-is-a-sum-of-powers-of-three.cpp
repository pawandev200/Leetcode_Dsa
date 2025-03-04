class Solution {
public:
   bool solve(int i, int t, vector<long long>&nums){
    // base case:
    if(t<0) return false; 
    if(t == 0) return true;  
    if(i==nums.size()) return false; 

    bool notTake = solve(i+1, t, nums);
    bool take = false; 
    if(nums[i]<=t) take = solve(i+1, t- nums[i], nums);

    return (take || notTake);
   }

    bool checkPowersOfThree(int n) {

        vector<long long>nums;  
        for(int i=0; i<=16; i++){
            long long num= pow(3, i);
            nums.push_back(num);
        }
        return solve(0, n, nums);
    }
};