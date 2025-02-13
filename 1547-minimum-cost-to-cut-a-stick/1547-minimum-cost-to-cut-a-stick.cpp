class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& cuts) {
        if (j - i <= 1) return 0; // no cuts left b/w i and j, no cost is incurred

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        // curr len = cuts[j] - cuts[i] and cost = len of rod being cut
        for (int k = i + 1; k < j; k++) { 
            int cost = cuts[j] - cuts[i] + solve(i, k, cuts) + solve(k, j, cuts);
            ans = min(ans, cost);
        } 
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        // Adding 0 and n at Boundaries: to cover full range and to find 1st cut val
        // If n = 7 and cuts = [1, 3, 5], adding boundaries gives [0, 1, 3, 5, 7].
        // Now, we can define segments like (0, 1), (1, 3), (3, 5), and (5, 7).
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        // preventing unnecessary duplicate computations by sorting
        sort(cuts.begin(), cuts.end()); // to process from smallest to largest

        dp.resize(c + 2, vector<int>(c + 2, -1)); 
        return solve(0, c + 1, cuts); // l = 0, r = cuts.size()-1;
    }
};
