class Solution {
public:
    vector<int> res;
    bool solve(int l, int n, vector<int>& arr, vector<bool>& used) {
        if (l == arr.size()) {
            res = arr;
            return true;
        }

        if (arr[l] != -1) return solve(l + 1, n, arr, used);

        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;

            int r = (num == 1) ? l : l + num;
            if (r < arr.size() && arr[r] == -1) {
                arr[l] = arr[r] = num;
                used[num] = true;

                if (solve(l + 1, n, arr, used)) return true;

                arr[l] = arr[r] = -1;
                used[num] = false;
            }
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        res.clear();
        vector<int> arr(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, arr, used);
        return res;
    }
};