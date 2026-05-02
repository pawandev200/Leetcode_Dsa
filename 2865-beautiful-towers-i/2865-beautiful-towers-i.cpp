class Solution {
public:
    long long maximumSumOfHeights(vector<int>& hts) {
        int n = hts.size();
        long long ans = 0; 
        for(int i=0; i<n; i++){
            int curr = hts[i];
            long long temp = 0; 
            for(int k=i-1; k>=0; k--){
                curr = min(curr, hts[k]);
                temp +=curr;
            }
            curr = hts[i];
            for(int k=i; k<n; k++){
                curr = min(curr, hts[k]);
                temp +=curr;
            }
            ans = max(ans, temp);
        }
        return ans; 
    }
};