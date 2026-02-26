class Solution {
public:
// if all possible substring of size k, contain in s: 2^k == distinct substr of given string 
    bool hasAllCodes(string s, int k) { 
        if(k>s.size()) return false; 

        unordered_set<string>st; 
        for(int i=0; i+k <= s.size(); i++){
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);  // 2^k 
    }
};