class Solution {
public:
    bool canTransform(string st, string res) {
        int n = st.size();
        
        int i = 0, j = 0;
        
        while(i < n || j < n){
            
            // skip X
            while(i < n && st[i] == 'X') i++;
            while(j < n && res[j] == 'X') j++;
            
            // both reached end
            if(i == n && j == n) return true;
            
            // one ended, other not
            if(i == n || j == n) return false;
            
            // mismatch character
            if(st[i] != res[j]) return false;
            
            // check movement rules
            if(st[i] == 'L' && i < j) return false;
            if(st[i] == 'R' && i > j) return false;
            
            i++; 
            j++;
        }
        
        return true;
    }
};