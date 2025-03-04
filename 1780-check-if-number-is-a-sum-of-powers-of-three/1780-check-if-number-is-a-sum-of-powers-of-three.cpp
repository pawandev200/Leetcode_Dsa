class Solution {
public:
    bool checkPowersOfThree(int n) {
        // if n can be represented using only 0s and 1s in base-3.
        while(n > 0){
            if(n % 3 == 2) return false; 
            n = n/3; 
        }
        return true; 
    }
};