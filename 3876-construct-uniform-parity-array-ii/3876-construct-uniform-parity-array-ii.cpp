class Solution {
public:

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size(); 
        // let's make all the ele odd, 
        int minodd = INT_MAX; 
        bool isodd = false; 
        for(int i=0; i<n; i++){
            if(nums1[i]%2){
                isodd = true; 
                minodd = min(minodd, nums1[i]);
            }
        }
        if(!isodd) return true; // all num is even
        // if even then try making odd => even - odd = odd
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0 && nums1[i] < minodd) return false; 
        }
        return true; 
    }
};