class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int pt = 0;

        // remove duplicates from beginning
        while (l < n && nums[l] == nums[n - 1]) l++;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] <= nums[n - 1]) {
                pt = mid;
                r = mid - 1; // pivot can be on left side
            }
            else {
                l = mid + 1; // pivot lies on right side
            }
        }

        return pt;
    }

// int pivot(vector<int>& nums, int l, int r) {
//     int pt = 0; 
//     while(l <= r) {
        
//         // Skip duplicates from left and right: 
//         while(l < r && nums[l] == nums[l+1]) l++;
//         while(r > l && nums[r] == nums[r-1]) r--;
        
//         int mid = l + (r - l) / 2;
        
//         if(nums[mid] <= nums[r]) { // sorted part, min is in [l, mid]
//             if (nums[mid] < nums[pt]) {
//                 pt = mid;  // Update only if we found smaller value
//             }
//             r = mid - 1;  // Search left
//         } else {  // unsorted part, min is in [mid+1, r]
//             l = mid + 1;  // Search right
//         }
//     }
    
//     return pt;
// }
    
    bool binarySearch(vector<int>& nums, int l, int r, int& t) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == t) return true;
            if(nums[mid] < t) l = mid+1;
            else r = mid-1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        
        int p = pivot(nums, 0 , n-1);
        cout <<"p = " << p << endl;

        if(binarySearch(nums, 0, p-1, t)) return true;

        return binarySearch(nums, p, n-1, t);
            
    }
};