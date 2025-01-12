class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 !=0) return false;  // If the length is odd, it can't be balanced

        // Left-to-right pass: Check if we can open enough to balance so far
        int opencnt = 0; 
        for(int i=0; i<n; i++){
            if(s[i] == '(' || locked[i] == '0') opencnt++; 
            else opencnt--; 
            if(opencnt < 0) return false; // Too many closing brackets
        }
        
        // Right-to-left pass: Check if we can close enough to balance so far 
        int closecnt = 0;
        for(int i= n-1; i>=0; i--){
            if(s[i] == ')' || locked[i] == '0') closecnt++; 
            else closecnt--; 
            if(closecnt < 0) return false; // Too many opening brackets
        }
        return true; 
    }
};