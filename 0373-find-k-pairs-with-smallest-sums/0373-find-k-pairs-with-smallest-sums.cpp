class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans; 

        // sum, idx1, idx2: 
        using piii = pair<int, pair<int, int>>;
        priority_queue<piii, vector<piii>, greater<piii>>pq; 
        
        for (int i = 0; i < min(n1, k); i++) pq.push({nums1[i] + nums2[0], {i, 0}});
       
        while(!pq.empty()){
            int sum = pq.top().first;
            int idx1 = pq.top().second.first;
            int idx2 = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[idx1], nums2[idx2]});
            k--; 
            if(k ==0) return ans;

            if(idx2 + 1 < n2) pq.push({nums1[idx1] + nums2[idx2 + 1], {idx1, idx2 + 1}});
        }
        return ans; 
    }
};