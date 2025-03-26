class Solution {
public:
    // Pivot check function: compare element at pos with the last element.

    int check(int pos, vector<int>& arr, int h) {
        if(arr[pos] < arr[h]) return 1;
        else if(arr[pos] > arr[h]) return 0;
        else return -1;  //if they are equal, used to shring search space
    }
    
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        if(n == 0) return false;
        
        int l = 0, h = n - 1, por = 0;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            int condition = check(mid, nums, n - 1);
            if(condition == 1) {        
                por = mid;              
                h = mid - 1;
            } else if(condition == 0) { 
                l = mid + 1;
            } else {  // nums[mid] == nums[n-1]
                h--;                   
            }
        }

        if(nums[por] >= nums[0]) por = 0; // no rotation
        
        // Segment1: indices [0, por - 1]  and Segment2: indices [por, n - 1]
        if(t >= nums[0]) {        
            l = 0;
            h = (por == 0 ? n - 1 : por - 1);
        } else {                   
            l = por;
            h = n - 1;
        }
        
        // Standard binary search using while(l <= h)
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == t) return true;
            else if(nums[mid] < t) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }
};
