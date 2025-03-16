class Solution {
public:
    int maximumCandies(vector<int>& cand, long long k) {
        int n = cand.size();
        long long l = 1; 
        long long r = *max_element(cand.begin(), cand.end());
        int ans = 0; 
        while(l<=r){
            long long mid = l + (r-l)/2; 

            long long tchild = 0; // chldren count
            for(int i=0; i<n; i++){
                tchild+= cand[i] / mid; 
                if(tchild>=k) break; 
            }
            if(tchild>=k){
                ans = mid; 
                l = mid+1; // trying larger one
            }
            else  r = mid - 1; 
        }
        return ans; 
    }
};