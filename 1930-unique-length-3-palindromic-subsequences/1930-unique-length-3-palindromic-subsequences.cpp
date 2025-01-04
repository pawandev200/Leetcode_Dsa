class Solution {
public:
    int countPalindromicSubsequence(string s) {

        // A set to store unique char of given string
        unordered_set<char>uniq; 
        for(auto it: s) uniq.insert(it);
        int cnt =0; 
        // and finding their starting and last pos in given string
        // and counting unique char between f and l  
        for(auto it: uniq){
            int f = s.find(it);
            int l = s.rfind(it);
            if(f<l){
                unordered_set<char>st; 
                for(int i=f+1; i<l; i++) st.insert(s[i]);
                cnt+=st.size();
            }
        }
        return cnt; 
    }
};