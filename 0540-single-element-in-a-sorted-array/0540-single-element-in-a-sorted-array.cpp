class Solution {
public:
/* 
for each pair, 1st ele takes even pos and 2nd ele takes odd pos: but this pattern get reversed after single ele appeared.
so we can break the array into two part using this property: 
check whether i am in correct manner: eoeoeo.. -> mid & mid+1 

this pattern follow then go to right part: answre present there. 
*/
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0; 
        int r = n-1;
        int ans = nums[0]; 
        while(l<=r){
            int mid = l + (r-l)/2;
            // if mid is even, dup should at it's next idx,
            //  if odd,  dup should be at it's prev idx.
            if(mid%2==1) mid--; // no need to handle two diff cases:  
            if(nums[mid] != nums[mid+1]){
                ans = nums[mid];
                r = mid - 1; 
            }
            else  l = mid + 2; // pattern is okay in lh 
        }
        return nums[l];
    }
};