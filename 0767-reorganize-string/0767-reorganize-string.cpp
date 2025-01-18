class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int>mp; 
        for(auto it: s) mp[it]++; 

        // max - heap to get two uniq max freq char: 
        // add them to ans and if freq>1 again push for next check: 
        priority_queue<pair<int, char>>pq; 
        for(auto it: mp) pq.push({it.second, it.first});

        string ans; 
        while(pq.size()>=2){
            auto [freq1, char1] = pq.top();
            pq.pop();
            auto [freq2, char2] = pq.top();
            pq.pop();
            ans+=char1; 
            ans+=char2;
            if(--freq1) pq.push({freq1, char1});
            if(--freq2) pq.push({freq2, char2});
        }
        if(!pq.empty()){
            auto [freq, char1] = pq.top();
            if(freq > 1) return "";
            ans+=char1;
        }
        return ans; 
    }
};