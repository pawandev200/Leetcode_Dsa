class Solution {
public:

    int digsum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        // the largest possible digit sume is 36(9999 => 9 + 9 + 9 + 9 = 36)
        vector<int> sums(37); 
        for (int i = 1; i <= n; i++) sums[digsum(i)]++;

        int maxi = 0;
        int cnt = 0;
        for (int i : sums) 
            if (i > maxi) maxi = i, cnt = 1;
            else if (i == maxi) ++cnt;
        
        return cnt;
    }
};