class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false; 

        vector<int> mtch; 

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) mtch.push_back(i);
            if (mtch.size() > 2) return false; 
        }

        if (mtch.empty()) return true;

        // If exactly 2 mismatches, check if swapping makes them equal
        if (mtch.size() == 2) {
            int idx1 = mtch[0];
            int idx2 = mtch[1];
            if(s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]) return true; 
        }
        return false; 
    }
};