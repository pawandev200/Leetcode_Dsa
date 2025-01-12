class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 !=0) return false; 

        int opencnt = 0; 
        for(int i=0; i<n; i++){
            if(s[i] == '(' || locked[i] == '0') opencnt++; 
            else opencnt--; 
            if(opencnt < 0) return false; 
        }
        opencnt = 0; 
        for(int i= n-1; i>=0; i--){
            if(s[i] == ')' || locked[i] == '0') opencnt++; 
            else opencnt--; 
            if(opencnt < 0) return false; 
        }
        return true; 
    }
};