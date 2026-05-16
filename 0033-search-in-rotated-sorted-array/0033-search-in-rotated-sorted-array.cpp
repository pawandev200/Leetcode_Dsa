class Solution {
public:
    int check(int pos, vector<int>&nums){
        int n = nums.size();
        if(nums[pos] < nums[0]) return 1; 
        return 0; 
    }
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int por = nums[0];

        // remove duplicates from beginning
        while (l < n && nums[l] == nums[n-1]) l++;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] <= nums[n-1]) {
                por = mid;
                r = mid - 1; // minimum can be on l side
            }
            else  l = mid + 1; // minimum lies on r side
        }
         
        // Now for searching the target: Bs on correct half:

        // if roation: nums[por] < nums[0]: then lp > rp
        // left part: 0 -> por-1; 
        // right part: por -> n-1;

        if (t >= nums[0]){ // means target in the left part of the array
            l = 0;
            r = (por == 0 ? n - 1 : por - 1); // if no rotation
        } else {
            l = por, r = n - 1;
        }

        int ans = -1; // default answer
        while(l<=r){
            int mid = l + (r - l)/2; 

            if(nums[mid] == t) return mid; 
            else if(nums[mid] < t) l = mid + 1; 
            else r = mid - 1; 
        }
        return -1;  
    }
};