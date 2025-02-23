class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string ss = s; 

        while(ss.size() >2){ 
            string temp;
            for(int i=0; i<ss.size()-1; i++){
                int sum = (ss[i] - '0' + ss[i+1] - '0') % 10; 
                temp+=to_string(sum);
            }
            ss = temp; // updating for next operations
        }
        if(ss.size() == 2 && ss[0] == ss[1]) return true; 
        return false; 
    }
};