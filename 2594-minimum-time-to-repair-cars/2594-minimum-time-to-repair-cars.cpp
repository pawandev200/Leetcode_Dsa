class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());

        // binary search on time: 
        long long l =1; 
        long long r = ranks[n-1]*(long long)cars*cars; // max time

        long long ans = 0; 
        while(l<r){
            long long mid = l + (r-l)/2;
            // now validaating this potential time mid:
            int tcars = 0;  
            for(int i=0; i<n; i++){
                tcars+= sqrt(mid/ranks[i]);
                if(tcars >=cars) break; 
            }
            if(tcars>=cars){
                ans = mid;
                r = mid; 
            }
            else l=mid+1;  
        }
        return l; 
    }
};