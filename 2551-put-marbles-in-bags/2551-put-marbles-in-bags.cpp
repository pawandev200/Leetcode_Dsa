class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k ==1 || n ==k) return 0; 

        vector<int>cand; 
        for(int i=0; i<n-1; i++) cand.push_back(weights[i] + weights[i+1]);

        sort(cand.begin(), cand.end());
        long long mins = 0; 
        long long maxs = 0; 
        for(int i=0; i<k-1; i++){
            mins+= cand[i];
            maxs += cand[n-2-i];
        }
        return maxs - mins; 
    }
};