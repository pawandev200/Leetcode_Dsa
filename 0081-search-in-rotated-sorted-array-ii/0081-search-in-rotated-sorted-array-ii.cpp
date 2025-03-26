class Solution {
public:
    int check(int pos, vector<int>&arr){
        if(arr[pos] < arr[0]) return 1; 
        return 0; 
    }
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        // first finding out the pivot(pt of rotation)
        int l = 0; 
        int h = n-1;
        int por = 0; // default val of rotation 
        while(l<=h){
            int mid = l + (h-l)/2; 
            if(check(mid, nums) == 1){
                por = mid; 
                h = mid -1; 
            }
            else l = mid + 1; 
        }

        // for searching the target: Bs on correct half:
        // if roation: nums[por] < nums[0]: then lp > rp
        // left part: 0 -> por -1; 
        // right part: por -> n-1;

        cout<<por<<endl; 
        if (t >= nums[0]){ // means target in the left part of the array
            l = 0;
            h = (por == 0 ? n - 1 : por - 1); // if no rotation
        } else {
            l = por, h = n - 1;
        }
       sort(nums.begin(), nums.end());
       l = 0;
       h = n-1;
        int ans = -1; // default answer
        while(l<=h){
            int mid = (l + h)/2; 

            if(nums[mid] == t) return true; 
            else if(nums[mid] < t) l = mid + 1; 
            else h = mid - 1; 
        }
        return false;  
    }
};