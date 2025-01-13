class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans; 
        int n = s.size();
        unordered_map<string, int>mp; 
        
        //taking string of size = 10 and checking it's freq
        for(int i=0; i<=n-10; i++){
            mp[s.substr(i, 10)]++;
        }

        for(auto it: mp){
            if(it.second >1) ans.push_back(it.first);
        }
        return ans; 
    }
};