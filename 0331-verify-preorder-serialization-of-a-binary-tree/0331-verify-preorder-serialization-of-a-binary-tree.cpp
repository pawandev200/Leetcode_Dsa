class Solution {
public:
    bool isValidSerialization(string preord) {
        stringstream ss(preord);
        int cap = 1; // initially either null or a node
        string st; 
        // reading val from string preord one by one 
        while(getline(ss, st, ',')){
            cap--; 
            if(cap<0) return false; // no of node is neg to possible 
            if(st != "#") cap+=2;  // if node then adding 2 for it's left and right
        }
        return cap ==0; 
    }
};