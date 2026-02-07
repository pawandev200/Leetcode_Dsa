class Solution {
public:
    const static int mod = 1e9 + 7; 
    int numSub(string s) {
        int n = s.size();
        int cnt = 0, total = 0; 
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++; 
            else cnt = 0; 
            total= (total + cnt)%mod; 
        }
        return total; 
    }
};