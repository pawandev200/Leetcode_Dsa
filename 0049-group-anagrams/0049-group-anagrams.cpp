class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // grouping all similar string: 
        unordered_map<string, vector<string>>mp;   
        for(const string& st: strs){
            string key = st; 
            sort(key.begin(), key.end());
            mp[key].push_back(st);
        }
        vector<vector<string>>ans; 
        for(const auto& it: mp) ans.push_back(it.second);

        return ans; 
    }
};