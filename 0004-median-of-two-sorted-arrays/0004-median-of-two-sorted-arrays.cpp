class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans; 
        int i=0, j=0; 
        while(i<n && j<m){
            if(nums1[i] <= nums2[j]) ans.push_back(nums1[i++]);
            else ans.push_back(nums2[j++]);
        }
        while(i<n) ans.push_back(nums1[i++]);
        while(j<m) ans.push_back(nums2[j++]);

        // now ans is sorted array
        double med = 0; 
        int size = ans.size();
        if(size % 2 != 0) med = (double)ans[size/2];
        else if(size % 2 == 0){
            int mid1 = size/2; 
            int mid2 = mid1--;
            med = (double)(ans[mid1] + ans[mid2])/2;
        }
        return med; 
    }
};