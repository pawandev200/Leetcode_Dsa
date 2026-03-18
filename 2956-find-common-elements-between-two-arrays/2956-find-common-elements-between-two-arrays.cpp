class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) { 
        unordered_set<int>st1, st2; 
        for(int i=0; i<nums1.size(); i++) st1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) st2.insert(nums2[i]);
        
        int ans1 = 0; 
        int ans2 = 0; 
        for(int i=0; i<nums1.size(); i++){
            if(st2.find(nums1[i]) != st2.end()) ans1++; 
        }
        for(int i=0; i<nums2.size(); i++){
            if(st1.find(nums2[i]) != st1.end()) ans2++; 
        }
        return {ans1, ans2};
    }
};