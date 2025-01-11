class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k)
            return false; // Not enough characters for k palindromes

        // Count the frequency of each character (a-z)
        vector<int> freq(26);
        for (int ch : s)
            freq[ch - 'a']++;

        // Count the number of characters with odd frequencies
        int oddcnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1)
                oddcnt++;
        }
        return oddcnt <= k; // True if odd counts fit in k palindromes
    }
};