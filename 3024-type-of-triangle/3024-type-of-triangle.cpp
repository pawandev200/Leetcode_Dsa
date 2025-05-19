class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_set<int>st;  
        for(int i=0; i<n; i++) st.insert(nums[i]);

        if(nums[0] + nums[1] <= nums[2]) return "none";

        int cnt = st.size();
        if(cnt ==1) return "equilateral";
        else if(cnt ==2) return "isosceles";
        return "scalene";
    }
};