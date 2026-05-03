class Solution {
public:
    bool rotateString(string s, string goal) {

        // // goals should be substring of s + s: 
        // if(s.size() != goal.size()) return false;
        // return (s + s).find(goal) != string::npos;

        int n = s.size();
        if(n != goal.size()) return false;
        if(s == goal) return true;  

        // checking each shift: shifting by 1 , 2, ... n-1
        for(int i = 0; i < n; i++) {
            string rotated = s.substr(i, n) + s.substr(0, i);
            if(rotated == goal) return true;
        }
        return false;
    }
};