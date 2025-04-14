class Solution {
public:
    bool check(int mid, int d, vector<int>& wt){
        int dcnt = 1;     
        int cap = 0;
        for(int i = 0; i < wt.size(); i++){
            if (cap + wt[i] > mid) {
                dcnt++;        
                cap = 0;
            }
            cap += wt[i];
        }
        return dcnt <= d;
    }

    int shipWithinDays(vector<int>& wt, int d) {
        int n = wt.size();
        
        int l = *max_element(wt.begin(), wt.end());
        int h = accumulate(wt.begin(), wt.end(), 0);
        int ans = h;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            if(check(mid, d, wt)){
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
