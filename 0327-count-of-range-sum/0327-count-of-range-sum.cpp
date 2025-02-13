class Solution {
public:
    int mergeSort(vector<long long>& sums, int l, int r, int low, int up) {
        if (r - l <= 1) return 0; // Base case

        int mid = l + (r - l) / 2;
        int count = mergeSort(sums, l, mid, low, up) + mergeSort(sums, mid, r, low, up);

        int j = mid, k = mid, t = mid;
        vector<long long> temp(r - l);
        int p = 0;

        for (int i = l; i < mid; i++) {
            // Count valid ranges
            while (k < r && sums[k] - sums[i] < low) k++;
            while (j < r && sums[j] - sums[i] <= up) j++;
            count += (j - k);

            // Merge step
            while (t < r && sums[t] < sums[i]) temp[p++] = sums[t++];
            temp[p++] = sums[i];
        }
        copy(temp.begin(), temp.begin() + p, sums.begin() + l);
        return count;
    }

    int countRangeSum(vector<int>& nums, int low, int up) {
        int n = nums.size();
        vector<long long> ps(n + 1, 0);
        
        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }

        return mergeSort(ps, 0, n + 1, low, up);
    }
};
