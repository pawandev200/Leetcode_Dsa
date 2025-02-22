class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (k > n) return false; 

        unordered_map<char, int> mp;
        int i = 0, j = 0;

        while (j < n) {
            mp[s[j]]++; // Expand the window 
            
            // If window size reaches k
            if (j - i + 1 == k) {
                if (mp.size() == 1) { 
                    bool leftOk = (i == 0 || s[i - 1] != s[i]);  
                    bool rightOk = (j == n - 1 || s[j + 1] != s[j]); 
                    if (leftOk && rightOk) return true;
                }

                // Shrink the window from the left
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++; // Expand the right side
        }
        return false;
    }
};
