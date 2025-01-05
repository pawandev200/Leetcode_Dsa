class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>netchanges(n+1, 0); // for precomputation, net change of each char

        for(auto it: shifts){
            int c1 = it[0];
            int c2 = it[1];
            int dir = it[2];

            netchanges[c1] += (dir == 1 ? 1 : -1);
            netchanges[c2 + 1] -= (dir == 1 ? 1 : -1);
        }

        int shift = 0; // Tracks the net shift at each position
        for (int i = 0; i < n; i++) {
           shift += netchanges[i]; // Accumulate the net shift
           shift = (shift % 26 + 26) % 26; 
           s[i] = 'a' + (s[i] - 'a' + shift) % 26; 
        }
        return s; 
    }
};