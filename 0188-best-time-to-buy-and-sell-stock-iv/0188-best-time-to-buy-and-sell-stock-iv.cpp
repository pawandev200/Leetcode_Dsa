class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n ==0 || k==0) return 0; 

        vector<int>buy(k, INT_MAX);
        vector<int>profit(k, 0);

        for(int i=0; i<n; i++){
            int cprice = prices[i];
            for(int j = 0; j<k; j++){
                buy[j] = min(buy[j], cprice - (j > 0 ? profit[j-1] : 0));
                profit[j] = max(profit[j], cprice - buy[j]);
            }
        }
        return profit[k-1];
    }
};