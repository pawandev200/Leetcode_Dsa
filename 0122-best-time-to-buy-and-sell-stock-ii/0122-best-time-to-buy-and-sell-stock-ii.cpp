class Solution {
public:

// just when you get the profit sell it, count the profit
//  add the profit for the later transections 

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0; // minimum profit 
        for(int i=1; i<n; i++){
            // buy on ith day and sell on (i+1)th day if there is profit  
            if(prices[i-1] < prices[i]){ 
                profit+=prices[i] - prices[i-1];
            }
        }
        return profit; 
    }
};