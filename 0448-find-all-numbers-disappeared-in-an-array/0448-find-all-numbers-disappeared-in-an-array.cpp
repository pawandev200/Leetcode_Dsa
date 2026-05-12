class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        // for x should be present at x-1th index, so mark x -1 prsent
        // unmark index's val will be answer: 
        for(int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0) { // preventing duplicate marking
                nums[idx] *= -1;
            }
        }

        vector<int> ans;

        // positive means missing
        for(int i = 0; i < n; i++) {

            if(nums[i] > 0) ans.push_back(i + 1);
        }

        return ans;
    }
};