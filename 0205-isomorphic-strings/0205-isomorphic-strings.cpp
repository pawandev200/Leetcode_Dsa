class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>freq1(256, -1); // ch, idx
        vector<int>freq2(256, -1); // ch, idx

        for(int i=0; i<s.size(); i++){
            if(freq1[s[i]] != freq2[t[i]]) return false; 
            freq1[s[i]] = i;
            freq2[t[i]] = i; 
        }
        return true; 
    }
};