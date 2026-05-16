class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int pt = 0;

        // remove duplicates from beginning
        while (l < n && nums[l] == nums[n - 1])
            l++;

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