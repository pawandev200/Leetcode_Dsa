class Solution {
public:
    // expanding(going away) from center and counting total palindromes 
    int expandfromctr(int l, int r, string& s) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--; // expanding to the left 
            r++; // expanding to the right
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int tcnt = 0;
        // iterating and treating each char as center
        for (int i = 0; i < s.size(); i++) {
            tcnt += expandfromctr(i, i, s); // one char as center: odd length
            tcnt += expandfromctr(i, i + 1, s); //two char as center:even length
        }
        return tcnt;
    }
};
