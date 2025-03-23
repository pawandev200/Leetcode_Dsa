class Solution {
public:
    int check(int pos, vector<int>&arr){
        if(arr[pos] < arr[0]) return 1; 
        return 0; 
    }
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        // first finding out the pivot(pt of rotation)
        int l = 0; 
        int h = n-1;
        int pot = 0; // default val of rotation 
        while(l<=h){
            int mid = l + (h-l)/2; 
            if(check(mid, nums) == 1){
                pot = mid; 
                h = mid -1; 
            }
            else l = mid + 1; 
        }

        // for searching the target: Bs on correct half: 
        if (t >= nums[0]) {
            l = 0, h = (pot == 0 ? n - 1 : pot - 1);
        } else {
            l = pot, h = n - 1;
        } 
        int ans = -1; // default answer
        while(l<=h){
            int mid = (l + h)/2; 

            if(nums[mid] == t) return mid; 
            else if(nums[mid] < t) l = mid + 1; 
            else h = mid - 1; 
        }
        return -1;  
    }
};