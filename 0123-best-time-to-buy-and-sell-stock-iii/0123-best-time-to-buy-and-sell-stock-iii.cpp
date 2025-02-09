class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b1 = INT_MAX; 
        int b2 = INT_MAX; 
        int s1 = 0; 
        int s2 = 0; 
        for(int i=0; i<n; i++){
            int cval = prices[i];
            b1 = min(b1, cval);
            s1 = max(s1, cval - b1); // getting max val from sell-1
            
            b2 = min(b2, cval-s1);
            s2 = max(s2, cval - b2); // getting max val from sell-2
        }
        return s2; 
    }
};