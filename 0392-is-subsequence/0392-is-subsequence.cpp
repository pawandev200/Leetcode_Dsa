class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int>pos[26];
        for(int i=0; i<t.size(); i++) pos[t[i]-'a'].push_back(i);

        int prev =-1; 

        for(const char& ch: s){
            auto& v = pos[ch-'a'];
            auto it = upper_bound(v.begin(), v.end(), prev);
            if(it == v.end()) return false; 

            prev = *it; 
        }
        return true; 
    }
};