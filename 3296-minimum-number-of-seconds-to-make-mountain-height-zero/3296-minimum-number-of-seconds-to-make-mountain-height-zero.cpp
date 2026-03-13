class Solution {
public:
    // is mid time enough for making height zero
    bool check(long long mid, vector<int>&wt, int mh){
        int n = wt.size();
        long long hr = 0; 
        for(int i=0; i<n; i++){
            long long val = 2*mid / wt[i];
            long long x = (sqrt(1+4*val)-1)/2; 
            hr +=x; 
            if(hr>=mh) return true; 
        }
        return false; 
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long l = 0; 
        long long r = 1e18; 
        long long ans = 0; 
        while(l<=r){
            long long mid = l + (r-l)/2; 
            if(check(mid, wt, mh)){
                ans = mid; 
                r = mid - 1; 
            } else l = mid + 1; 
        }
        return ans; 
    }
};