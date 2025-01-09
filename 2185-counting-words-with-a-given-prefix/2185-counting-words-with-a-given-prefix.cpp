class Solution {
public:
    bool check(string st, string pref){
        if(st.size() < pref.size()) return false; 
        for(int i=0; i<pref.size(); i++){
            if(st[i]!=pref[i]) return false; 
        }
        return true; 
    }
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int cnt =0; 
        for(int i=0; i<n; i++){
            if(check(words[i], pref)) cnt++; 
        }
        return cnt;  
    }
};