class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; // proc, freq
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++; 
            }
        }
        int ans =0; 
        for(auto it: mp){
            int cnt = it.second; 
            if(cnt > 1) ans+= cnt*4; 
        }
        return ans; 
    }
};