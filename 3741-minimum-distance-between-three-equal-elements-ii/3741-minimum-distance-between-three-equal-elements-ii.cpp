class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>>mp; // num, idxs
        for(int i=0; i<n; i++) mp[nums[i]].push_back(i);

        int ans = INT_MAX; 
        for(auto &it: mp){
            if(it.second.size()>=3){
                for(int i=2; i<it.second.size(); i++){
                    int a = it.second[i-2];
                    int b = it.second[i-1];
                    int c = it.second[i];
                    int dist = abs(a-b) + abs(b-c) + abs(c-a);
                    ans = min(ans, dist);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans; 
    }
};