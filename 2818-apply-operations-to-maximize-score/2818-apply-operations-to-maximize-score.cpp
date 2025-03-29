class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to get the number of distinct prime factors of n
    int primeFactors(int n) {
        int i = 2;
        unordered_set<int> ans;
        while (i * i <= n) {
            while (n % i == 0) {
                ans.insert(i);
                n /= i;
            }
            i++;
        }
        if (n > 1) ans.insert(n);
        return ans.size();
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> arr; 
        
        // Create an array of vectors {index, prime factor count, value}
        for (int i = 0; i < n; i++) {
            arr.push_back({i, primeFactors(nums[i]), nums[i]});
        }

        vector<int> left(n, -1), right(n, n);
        stack<pair<int, int>> stk;

        // Calculate the left boundary
        for (auto& v : arr) {
            int i = v[0], f = v[1], x = v[2];
            while (!stk.empty() && stk.top().first < f) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top().second;
            }
            stk.push({f, i});
        }

        // Clear stack and calculate the right boundary
        while (!stk.empty()) stk.pop();
        for (int j = n - 1; j >= 0; j--) {
            int i = arr[j][0], f = arr[j][1], x = arr[j][2];
            while (!stk.empty() && stk.top().first <= f) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top().second;
            }
            stk.push({f, i});
        }

        // Sort arr by value in descending order
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });

        long long ans = 1;
        for (auto& v : arr) {
            int i = v[0], f = v[1], x = v[2];
            int l = left[i], r = right[i];
            long long cnt = (long long)(i - l) * (r - i);

            if (cnt <= k) {
                ans = ans * powMod(x, cnt, MOD) % MOD;
                k -= cnt;
            } else {
                ans = ans * powMod(x, k, MOD) % MOD;
                break;
            }
        }

        return ans;
    }

    // Function to compute (base^exp) % mod using fast exponentiation
    long long powMod(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};
