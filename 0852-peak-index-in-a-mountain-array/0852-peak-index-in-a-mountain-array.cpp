class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l =0; 
        int r = n-1; 
        int ans = -1; 

        while(l<=r){
            int mid = l + (r-l)/2;

            bool left = (mid == 0 || arr[mid] > arr[mid - 1]);
            bool right = (mid == n - 1 || arr[mid] > arr[mid + 1]);
    
            if (left && right) return mid;
 
            if(mid + 1 < n && arr[mid] > arr[mid + 1]) r = mid - 1; 
            else l = mid + 1; 
        }
        return ans; 
    }
};