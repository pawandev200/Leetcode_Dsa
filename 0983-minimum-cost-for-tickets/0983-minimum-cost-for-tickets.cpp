class Solution {
public:

vector<int>dp;
int solve(int i, unordered_set<int>& tdays, vector<int>& costs){
    // Base case: if we've processed all days, return 0
    if (i > 365) return 0;

    if (dp[i] != -1) return dp[i];

    int res;
    if (tdays.find(i) == tdays.end()) {
        // If it's not a travel day, move to the next day
        res = solve(i + 1, tdays, costs);
    } else {
        // If it's a travel day, then cost for 1-day, 7-day, and 30-day passes
        int cost1day = costs[0] + solve(i + 1, tdays, costs);
        int cost7day = costs[1] + solve(i + 7, tdays, costs);
        int cost30day = costs[2] + solve(i + 30, tdays, costs);

        res = min({cost1day, cost7day, cost30day});
    } 
    return dp[i] = res;
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        unordered_set<int> tdays(days.begin(), days.end());

        dp.resize(366, -1);

    // Start the recursion from the first travel day
    return solve(days[0], tdays, costs);
    }
};