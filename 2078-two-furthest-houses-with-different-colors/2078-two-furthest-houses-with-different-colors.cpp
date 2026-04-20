class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        unordered_map<int, int>mp; // num, idx
        for(int i=0; i<n; i++) mp[colors[i]] = i; 

        if(mp.size()<=1) return 0; 
        int ans = 0; 
        for(int i=0; i<n; i++){
            for(const auto& [num, idx]: mp){
                if(num!=colors[i]) ans = max(ans, abs(idx - i));
            }
        }
        return ans; 
    }
};