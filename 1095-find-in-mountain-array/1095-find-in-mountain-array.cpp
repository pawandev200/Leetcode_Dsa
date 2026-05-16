/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    // edge (0 or n-1) can't be maxima, len >=3 for this: 
    int getMaxima(MountainArray &nums){
        int n = nums.length();
        
        int l = 1; 
        int r = n-2; 
        int idx = n-2; 

        while(l<=r){
            int mid = l + (r-l)/2;

            int val = nums.get(mid);
            int rs = nums.get(mid+1); 

            bool left = (val > nums.get(mid-1));
            bool right = (val > rs);
    
            if (left && right) return mid;

            // given, plateau can NEVER happen 
            if(val > rs) r = mid - 1; 
            else l = mid + 1; 
        }
        return idx; 
    }

    // how will you ensure it is minimum: by calculating left part first
    int binarySearch1(MountainArray &nums, int t, int l, int r){
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2; 
            int val = nums.get(mid); 
            if(val == t) return mid; 
            else if(val < t) l = mid + 1; 
            else r = mid - 1; 
        }
        return ans; 
    }
    int binarySearch2(MountainArray &nums, int t, int l, int r){
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2; 
            int val = nums.get(mid);
            if(val == t) return mid; 
            else if(val < t) r = mid -1; 
            else l = mid + 1; 
        }
        return ans; 
    }
    
    int findInMountainArray(int t, MountainArray &nums) {

        int idx = getMaxima(nums);

        // left part first to ensure minimum target's index: 
        int left = binarySearch1(nums, t, 0, idx);
        if(left !=-1) return left; 

        return binarySearch2(nums, t, idx, nums.length()-1);

    }
};