class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, mins = 0, maxs = 0;
        for (int num : nums) {
            sum += num;
            if (sum > maxs) maxs = sum;
            if (sum < mins) mins = sum;
        }
        cout<<maxs<<" "<<mins<<endl;
        return abs(maxs - mins);
    }
};