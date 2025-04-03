class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long ans = 0;
        int maxa = 0, maxab = 0;
        for (int&a : A) {   
            ans = max(ans, 1LL * maxab * a);
            maxab = max(maxab, maxa - a);
            maxa = max(maxa, a);
        }
        return ans;
    }
};