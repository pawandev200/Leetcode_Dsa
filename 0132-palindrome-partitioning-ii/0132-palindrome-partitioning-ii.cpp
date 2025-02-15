class Solution {
public:
    bool ispalindrome(int i, int j, string &s){
        while(i<=j){
            if(s[i++] !=s[j--]) return false; 
        }
        return true; 
    }

    vector<vector<int>>dp; 
    int solve(int i, int j, string &s){
        if(i>=j) return 0; // 0 or 1 ele always palindrom so no cuts
        if (ispalindrome(i, j, s)) return 0;

        if(dp[i][j] !=-1) return dp[i][j];

        int ans = 1e9;
        for(int k = i; k<j; k++){
            if(ispalindrome(i, k, s)){ // if left part palindrome checking rp
                ans = min(ans, 1 + solve(k+1, j, s));
            }
        }
        return dp[i][j] = ans; 
    }
    int minCut(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1, s);
    }
};