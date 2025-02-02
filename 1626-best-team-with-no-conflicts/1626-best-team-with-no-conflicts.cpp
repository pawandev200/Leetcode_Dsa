class Solution {
public:
    vector<vector<int>>dp; 
    int solve(int i, int prev, vector<pair<int, int>>& p){
        // base case:
        if(i==p.size()) return 0;  
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        // confilict:
        int notTake = solve(i+1, prev, p);
        int take = INT_MIN; 
        if(prev==-1 || p[i].second >= p[prev].second){
            take = p[i].second + solve(i+1, i, p);
        }
        return dp[i][prev+1] = max(take, notTake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>>players; 
        for(int i=0; i<n; i++) players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());

        dp.resize(n+1, vector<int>(n+1, -1));

        return solve(0,-1, players);
    }
};