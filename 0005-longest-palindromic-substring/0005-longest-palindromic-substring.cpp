class Solution {
public:
string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }

    // DP table to store whether s[i...j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Initialize variables to track the longest palindrome
    int max_length = 1;  // Length of the longest palindrome found so far
    int start = 0;       // Starting index of the longest palindrome

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            max_length = 2;
            start = i;
        }
    }

    // Check for substrings longer than 2
    for (int length = 3; length <= n; length++) {  // Length of the substring
        for (int i = 0; i < n - length + 1; i++) {  // Starting index
            int j = i + length - 1;  // Ending index
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (length > max_length) {
                    max_length = length;
                    start = i;
                }
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, max_length);
}
};