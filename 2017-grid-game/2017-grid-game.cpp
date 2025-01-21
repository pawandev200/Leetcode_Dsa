class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();
        
        long long topsum = 0;
        long long bsum =0;
        long long minsum = LLONG_MAX; // robot-1 wants to minimize the sum for robot-2 
        for(long long i=0; i<n; i++) topsum+=grid[0][i];

        for(long long i=0; i<n; i++){
            topsum-=grid[0][i]; //possible partition point
            minsum = min(minsum, max(topsum, bsum));
            bsum +=grid[1][i];
        }
        return minsum; 
    }
};