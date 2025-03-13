class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int>mp; 
        for(auto it: intervals){
            int f = it[0];
            int l = it[1];
            mp[f]+=1; 
            mp[l+1]-=1; 
        }
        int sum =0; 
        int ans =0; 
        for(auto it: mp){
            sum+=it.second; 
            ans = max(ans, sum);
        }
        return ans; 
    }
};