class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>>mp; // num, last two idxs
        int ans = INT_MAX; 

        for(int i=0; i<n; i++){
            int cv = nums[i];
            if(mp.count(cv)){
                int f = mp[cv].first; 
                int s = mp[cv].second; 
                if(f!=-1) ans = min(ans, 2*(i-f));

                mp[cv] = {s, i};
            } else mp[cv] = {-1, i};
        }

        return ans == INT_MAX ? -1 : ans; 
    }
};