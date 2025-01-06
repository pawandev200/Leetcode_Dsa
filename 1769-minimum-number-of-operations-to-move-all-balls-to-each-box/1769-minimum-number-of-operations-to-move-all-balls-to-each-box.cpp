class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int nbl = 0, mfl = 0;
        int nbr = 0, mfr = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            ans[i] += mfl;
            nbl += boxes[i] - '0';
            mfl += nbl;

            // Right pass
            int j = n - 1 - i;
            ans[j] += mfr;
            nbr += boxes[j] - '0';
            mfr += nbr;
        }

        return ans;
    }
};