class Solution {
public:
    string removeOccurrences(string s, string part) {

        while ((s.find(part)) != -1) {  
            int idx = s.find(part);   
            s.erase(idx, part.size());   
        }
        return s;
    }
};
