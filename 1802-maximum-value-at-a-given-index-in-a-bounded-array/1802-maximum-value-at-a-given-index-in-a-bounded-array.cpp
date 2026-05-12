class Solution {
public:

    long long getsum(int cnt, int maxi){

        // enough decreasing numbers
        if(maxi > cnt){

            long long low = maxi - cnt;

            return (maxi - 1 + low) * 1LL * cnt / 2;
        }

        // reaches 1
        else{

            long long aps = 1LL * (maxi - 1) * maxi / 2;

            long long ones = cnt - (maxi - 1);

            return aps + ones;
        }
    }

    bool check(int mid, int n, int idx, int maxs){

        long long sum = mid;

        // left side
        sum += getsum(idx, mid);

        // right side
        sum += getsum(n - idx - 1, mid);

        return sum <= maxs;
    }

    int maxValue(int n, int idx, int maxs) {

        int l = 1;
        int r = maxs;
        int ans = 1;

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(check(mid, n, idx, maxs)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};