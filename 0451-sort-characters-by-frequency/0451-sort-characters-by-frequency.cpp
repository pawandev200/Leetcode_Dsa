class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int>mp; 
        for(auto it: s) mp[it]++;

        // sorting based on freq: 
        vector<pair<int,char>>freq; 
        for(auto it: mp){
            freq.push_back({it.second, it.first});
        }
        auto comp = [](pair<int, char>&a, pair<int, char>&b){
            return a.first > b.first;
        };
        sort(freq.begin(), freq.end(), comp);

        string ans; 
        for(auto it: freq){
            ans.append(it.first, it.second); //it.first: freq times 
        } 
        return ans; 
    }
};