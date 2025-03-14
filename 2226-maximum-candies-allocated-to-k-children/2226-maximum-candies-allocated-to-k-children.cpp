class Solution {
public:
    // function to check, x candy can we divided among k childs or not: 
    bool check(int x, long long k, vector<int>&candies){
        int n = candies.size();
        long long cnt = 0; 
        for(int i=0; i<n; i++){
            cnt+=candies[i]/x; 
            if(cnt>=k) return true; // can be divided
        }
        return false; 
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long tsum = 0; 
        int maxi = 0; 
        for(int i=0; i<n; i++){
            tsum+=candies[i];
            maxi = max(maxi, candies[i]);
        }
        if(tsum<k) return 0; 

        // applying bs: 1 to maxi and try to maximize the candies distribution
        int l = 1;
        int r = maxi;
        int ans = 0;  
        while(l<=r){
            int mid = l + (r-l)/2; 
            if(check(mid, k, candies)){ 
                ans = mid; // trying larger number of candy 
                l = mid+1; 
            }
            else r = mid-1; 
        } 
        return ans; 
    }
};