class Solution {
public:
// Finish the current pile first: 
// Koko focuses on eating all the bananas in one pile before moving on to the next pile.

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int l = 1; 
        int r = piles[n-1]; // max time to eat: max val of piles
        while(l<r){
            int mid = l + (r-l)/2; 
            // checking for mid speed can all banana be eaten under h hours:
            int th = 0;  
            for(int i=0; i<n; i++){
                th += (piles[i] + mid - 1)/mid; 
            }
            if(th<=h) r = mid; 
            else l = mid+1; 
        }
        return l; 
    }
};