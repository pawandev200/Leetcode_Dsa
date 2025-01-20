class Solution {
public:
    string convert(string s, int r) {
        int n = s.size();
        if(r==1 || r>=n) return s; 

        vector<vector<char>>rows(r);
        int idx = 0; 
        int d = 1; 
        for(int i =0; i<n; i++){
            rows[idx].push_back(s[i]);
            if(idx == 0) d =1; 
            else if(idx == r-1) d= -1; 
            idx +=d; 
        }

        string ans; 
        for(auto it: rows){
            for(int ch: it){
                ans+=ch;
            }
        }
        return ans; 
    }
};