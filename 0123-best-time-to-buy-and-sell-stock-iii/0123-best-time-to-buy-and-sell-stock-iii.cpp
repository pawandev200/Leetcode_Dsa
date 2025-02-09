class Solution {
public:
// After making profit p1 from the 1st transaction, for the 2nd transaction,
// suppose buying amount is x then net you are spending is x - p1 and then sell 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b1 = INT_MAX; 
        int b2 = INT_MAX; 
        int p1 = 0; 
        int p2 = 0; 
        for(int i=0; i<n; i++){
            int cval = prices[i];
            b1 = min(b1, cval); //lowest price seen so far for 1st transection
            p1 = max(p1, cval - b1); // getting max val from sell-1
            
            // effective buying price for the 2nd transection
            b2 = min(b2, cval-p1); //lowest price seen so far for 2nd transection
            p2 = max(p2, cval - b2); // getting max val from sell-2
        }
        return p2; 
    }
};