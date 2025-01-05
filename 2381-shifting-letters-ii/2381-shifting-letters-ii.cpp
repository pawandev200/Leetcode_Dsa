class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>changes(n+1, 0); // for precomputation, net change of each char

        for(auto it: shifts){
            int c1 = it[0];
            int c2 = it[1];
            int dir = it[2];

            changes[c1] += (dir == 1 ? 1 : -1);
            changes[c2 + 1] -= (dir == 1 ? 1 : -1);
        }

        // finding the prefix sum: for net changes at each index
        int shift = 0;
        for (int i = 0; i < n; i++) {
           shift += changes[i]; 
           shift = (shift % 26 + 26) % 26; // wrapping the shift around a<->z
           s[i] = 'a' + (s[i] - 'a' + shift) % 26; 
        }
        return s; 
    }
};