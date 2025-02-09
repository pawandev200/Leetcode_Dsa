class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       
        int bestBuy = INT_MIN;  // Best profit if the last action was a buy
        int bestSell = 0;       // Best profit if the last action was a sell

        // Iterate through each stock price
        for (int currentPrice : prices) {
            // Update the best buying state:
            // Either keep the previous best buy, or buy the stock at the current price
            // (using the profit from the last sell to fund the purchase)
            bestBuy = max(bestBuy, bestSell - currentPrice);

            // Update the best selling state:
            // Either keep the previous best sell, or sell the stock at the current price
            // (adding the current price to the best buy state and subtracting the fee)
            bestSell = max(bestSell, bestBuy + currentPrice - fee);
        }

        // The maximum profit is stored in bestSell
        return bestSell;
    }
};