class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int f = 0, s = 0; 
        int fc = 0, sc = 0; 
        for(const int& num: nums){ 
            if(f == num) fc++; 
            else if(s == num) sc++; 
            else if (fc == 0) {f = num; fc++;} 
            else if(sc ==0) {s = num; sc++;}
            else {
                fc--; 
                sc--; 
            }
        }
        if(f == s) return {f};

        // verification: 
        fc = 0;
        sc = 0; 
        for(const int& num: nums){
            if(num==f) fc++; 
            else if(num==s) sc++; 
        }
        vector<int>ans;
        int th = nums.size()/3; 

        if(fc > th) ans.push_back(f);
        if(sc > th) ans.push_back(s);

        return ans; 
    }
};