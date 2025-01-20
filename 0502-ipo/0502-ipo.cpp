class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c){
        int n = p.size();

        vector<pair<int, int>>proj;
        // for a proj: spenting c[i] to make profit p[i]: 
        //  we spent min cap and find max profit:  
        for(int i=0; i<n; i++) proj.push_back({c[i], p[i]});
        sort(proj.begin(), proj.end());

        // max - heap to maximize the profit after kth projects: 
        priority_queue<int>maxheap;

        int i =0; // traversing in proj and choosing cap and profit:  
        while(k--){
            while(i<n && proj[i].first <=w){
                maxheap.push(proj[i].second);
                i++;
            }
            if(maxheap.empty()) break; 
            w+=maxheap.top();
            maxheap.pop();
        }
        return w; 
    }
};