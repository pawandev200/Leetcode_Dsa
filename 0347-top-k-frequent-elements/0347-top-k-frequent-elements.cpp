class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans; 
        unordered_map<int,int>mp; // num, freq
        for(int i=0; i<n; i++) mp[nums[i]]++;

        // min - heap to sort on the basis of freq: 
       priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int, int>>>pq; //freq, num
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop(); 
        }

        while(pq.size()>0){
            // k--; 
            ans.push_back(pq.top().second);
            pq.pop();
            // if(k ==0) break;
        }
        return ans; 
    }
};