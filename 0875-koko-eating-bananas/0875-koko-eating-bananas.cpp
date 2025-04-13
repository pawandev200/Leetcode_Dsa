class Solution {
public:

   bool check(int mid, int h, vector<int>& piles){
       int tt = 0; 
       for(int i=0; i<piles.size(); i++){
        tt += (piles[i] + mid - 1) / mid;
        if(tt>h) return false; 
       }
       return tt<=h; 
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        // binary search on answer: 
        int l = 1; 
        int hi = *max_element(piles.begin(), piles.end());
        int ans = 0; 
        while(l<=hi){
            int mid = l + (hi-l)/2;
            if(check(mid, h, piles)){
                ans = mid; 
                hi = mid -1; 
            }
            else l = mid + 1; 
        }
        return ans; 
    }
};