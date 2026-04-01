class Solution {
public:
    const static int mod = 1e9 + 7; 
    int threeSumMulti(vector<int>& nums, int tar) {
        int n = nums.size();
        // sort(nums)
        long long cnt = 0; 
        for(int i=0; i<n; i++){
            int t = tar - nums[i];

            unordered_map<int, int>mp; 
            for(int j = i+1; j<n; j++){
                int comp = t - nums[j];
                if(mp.find(comp) != mp.end()){
                    // if(j > mp[comp] > i)
                     cnt+= (mp[comp]% mod); 
                } 
                mp[nums[j]]++; ; 
            }
        }
        return (int)(cnt%mod); 
    }
};