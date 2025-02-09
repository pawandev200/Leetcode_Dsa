class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Initialize buy and profit arrays
        vector<int> buy(k, INT_MAX); // Eff buying price for each transaction
        vector<int> profit(k, 0);    // Maximum profit after each transaction

        for (int i = 0; i < n; i++) {
            int currentPrice = prices[i];

            // Update buy and profit for each transaction
            for (int j = 0; j < k; j++) {
                // Effective buying price for the j-th transaction
                buy[j] = min(buy[j], currentPrice - (j > 0 ? profit[j - 1] : 0));

                // Maximum profit after the j-th transaction
                profit[j] = max(profit[j], currentPrice - buy[j]);
            }
        }
        return profit[k - 1]; // max profit after k transections
    }
};