class Solution {
public:
    int getrev(int x){
        int rev = 0; 
        while(x>0){
            rev = 10*rev + x%10; 
            x = x/10; 
        }
        return rev; 
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; // rev, idx
        int ans = n; 
        for(int i=0; i<n; i++){
            int rev = getrev(nums[i]);
            auto it = mp.find(nums[i]);
            if(it != mp.end()){
                int idx = it->second; 
                ans = min(ans, abs(i-idx));
            }
            mp[rev] = i; 
        }
        // for(auto it: mp) cout<<it.first<<",";
        return ans == n ? -1 : ans; 
    }
};