class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0; 
        int j = 0; 
        vector<int>nums; 
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while(i<n) nums.push_back(nums1[i++]);
        while(j<m) nums.push_back(nums2[j++]);
        int t = nums.size();
        if(t%2) return (double)(nums[t/2]);
        else {
            int a = nums[t/2];
            int b = nums[t/2-1];
            return (double)(a+b)/2.0; 
        }
        return 0.0; // never run; 
    }
};