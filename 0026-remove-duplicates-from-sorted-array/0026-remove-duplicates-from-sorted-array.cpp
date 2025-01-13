class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle the case for empty array

    int k = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[k] != nums[i]) {
            k++;
            nums[k] = nums[i];
        }
    }
    return k + 1; // Length of the array without duplicates
}

};