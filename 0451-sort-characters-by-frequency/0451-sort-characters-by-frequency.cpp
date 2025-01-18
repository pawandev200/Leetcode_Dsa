class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int>mp; 
        for(auto it: s) mp[it]++;

        // sorting based on freq: 
        priority_queue<pair<int, char>>pq; // max - heap
        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        // now building ans: 
        string ans; 
        while(!pq.empty()){
            int freq = pq.top().first; 
            for(int i=0; i<freq; i++) ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans; 
    }
};