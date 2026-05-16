class Solution {
public:
    bool check(int mid, vector<int>&nums){
        int n = nums.size();
        if(nums[mid] < nums[n-1]) return true; 
        return false; 
    }

    int binarySearch(vector<int>& nums, int l, int r, int& t) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == t) return mid;
            if(nums[mid] < t) l = mid+1;
            else r = mid-1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int pt = nums[0];

        // remove duplicates from beginning
        while (l < n && nums[l] == nums[n-1]) l++;

        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[mid] <= nums[n-1]) {
                pt = mid;
                r = mid - 1; 
            }
            else l = mid + 1; 
        }

        int lv = binarySearch(nums, 0, pt-1, t);
        int rv = binarySearch(nums, pt, n-1, t);

        if(lv != -1) return lv;
        return rv == -1 ? -1 : rv;


        // if (t >= nums[0]){ // means target in the left part of the array
        //     l = 0;
        //     r = (pt == 0 ? n - 1 : pt - 1); // if no rotation
        // } else {
        //     l = pt, r = n - 1;
        // }

        // int ans = -1; // default answer
        // while(l<=r){
        //     int mid = l + (r - l)/2; 

        //     if(nums[mid] == t) return mid; 
        //     else if(nums[mid] < t) l = mid + 1; 
        //     else r = mid - 1; 
        // }
        // return ans;  
    }
};