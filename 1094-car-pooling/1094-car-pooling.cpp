class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        map<int, int>mp; 

        for(auto it: trips){
            int ps = it[0];
            int f = it[1];
            int t = it[2];
            mp[f]+=ps; 
            mp[t]-=ps; 
        }
        int sum = 0; 
        for(auto it: mp){
            sum+=it.second; 
            if(sum>cap) return false; 
        }
        return true; 
    }
};