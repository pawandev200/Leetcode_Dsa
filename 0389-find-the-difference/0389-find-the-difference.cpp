class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>freq(26, 0);
        for(const char& ch: s) freq[ch-'a']++; 

        for(const char& ch: t){
            int temp = ch - 'a';
            if(freq[ch - 'a'] == 0) return ch; 
            freq[ch- 'a']--; 
        }
        return ' ';
    }
};