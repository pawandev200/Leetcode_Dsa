class Solution {
public:
int maxProfit(vector<int>& prices) {
    // Initialize variables to track the best buying and selling states
    int bestBuy = INT_MIN;  // Best profit if the last action was a buy
    int bestSell = 0;       // Best profit if the last action was a sell
    int prevSell = 0;       // Profit from the previous sell (to handle cooldown)

    // Iterate through each stock price
    for (int price : prices) {
        // Store the previous bestBuy value before updating it
        int prevBuy = bestBuy;

        // Update the best buying state:
        // Either keep the previous bestBuy, or buy the stock at the current price
        // (using the profit from the previous sell to fund the purchase, considering cooldown)
        bestBuy = max(prevSell - price, bestBuy);

        // Update the previous sell state for the next iteration
        prevSell = bestSell;

        // Update the best selling state:
        // Either keep the previous bestSell, or sell the stock at the current price
        // (adding the current price to the previous bestBuy state)
        bestSell = max(prevBuy + price, bestSell);
    }

    // The maximum profit is stored in bestSell
    return bestSell;
}
};