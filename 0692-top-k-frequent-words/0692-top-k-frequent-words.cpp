class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int>mp; 
        for(auto it: words) mp[it]++; 

        // sorted based on freq: top k frequent need to keep: min - heap: 
        // custom comparator to sort by frequency, and lexicographically for ties.
        auto comp = [](pair<int, string>&a, pair<int, string>&b){
            if(a.first == b.first) return a.second < b.second; 
            return a.first > b.first; 
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)>pq(comp); // freq, string

        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string>ans; 
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); // since least freq on top of pq
        return ans; 
    }
};