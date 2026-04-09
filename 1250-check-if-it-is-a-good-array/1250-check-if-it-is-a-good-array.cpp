class Solution {
public:
    // take only that elements which are coprime into comb: 
    // ax + by = 1 => gcd(a, b) = 1
    // if any coprime pair formed then it is always possible: 

    int gcd(int a, int b){
        if(b==0) return a; 
        return gcd(b, a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int gsf = 0; // gsf(0, x) = x 
        for(int i=0; i<n; i++){
            gsf = gcd(gsf, nums[i]); 
            if(gsf ==1) return true; 
        }
        return false; 
    }
};