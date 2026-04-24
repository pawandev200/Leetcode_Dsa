class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0; 
        int buff = 0; 
        for(const char& mv: moves){
            if(mv =='R') cnt++; 
            else if(mv =='L') cnt--; 
            else buff++; 
        }
        return abs(cnt) + buff; 
    }
};