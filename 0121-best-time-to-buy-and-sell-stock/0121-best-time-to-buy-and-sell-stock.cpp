class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0; 
        // price ghati to buy, badhi to sell 
        for(int i=1; i<prices.size(); i++){
            if(buy > prices[i]) buy = prices[i];
            else {
                int sell = prices[i] - buy;
                // if(prices[i] - buy > profit) profit = prices[i] - buy;
                profit = max(profit, sell);
            }
        }
        return profit; 
    }
};