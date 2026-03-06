class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        if(n<=2) return true; 
        int p = 0; 
        int cnt = 0; 
        for(int i=1; i<n; i++){
            if(s[i]=='0' && s[p]=='1'){
                cnt++; 
            }
            if(s[i]=='1' && s[p]=='0'){
                cnt++; 
            }
            if(cnt>1) return false; 
            p = i; 
        }
        return true; 
    }
};