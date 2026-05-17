class Solution {
public:
    bool check(int mid, int d, vector<int>&wt){
        int cnt = 1; 
        int cs = 0; 
        for(const int& w: wt){
            if(w>mid) return false; 
            else if(cs + w > mid){
                cnt++; 
                cs = w; // new start
            } else cs +=w; 
        }
        return cnt <= d; 
    }
    int shipWithinDays(vector<int>& wt, int d) {
        int n = wt.size();

        // applying bs on capacity: 
        int l = *max_element(wt.begin(), wt.end());
        int r = accumulate(wt.begin(), wt.end(), 0);
        int ans = -1; 
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(mid, d, wt)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans; 
    }
};