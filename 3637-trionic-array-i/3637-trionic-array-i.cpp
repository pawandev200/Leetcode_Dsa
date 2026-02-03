class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        // searching p & q indices: 0<p<q<n-1; 
        while(i<n-1 && nums[i] < nums[i+1]) i++;  // inc
        if(i==0 || i==n-1) return false; 

        int p = i; 
        while(i<n-1 && nums[i] > nums[i+1]) i++;  // dec
        if(i==p || i==n-1) return false;
        
        int q = i; 
        while(i<n-1 && nums[i] < nums[i+1]) i++;  // again inc

        return i==n-1; // no more ele left to scan: no more down from here
    }
};