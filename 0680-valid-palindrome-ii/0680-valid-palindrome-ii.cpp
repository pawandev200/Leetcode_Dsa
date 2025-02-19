class Solution {
public:

   bool solve(int i, int j, string &s){
        while(i<=j){
            if(s[i]!=s[j]) return false; 
            i++; 
            j--; 
        }
        return true;
   }
    bool validPalindrome(string s) {
        int n = s.size();
        int i =0; 
        int j =n-1; 
        while(i<=j){
            if(s[i]!=s[j]){
                return solve(i+1, j, s) || solve(i,j-1, s);
            }
            else {
                i++; 
                j--; 
            }
        }
        return true;
    }
};