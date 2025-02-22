class Solution {
public:
    long long maxWeight(vector<int>& p) {
        sort(p.begin(), p.end()); 
        int n = p.size();
        int m = n / 4;  // total days
        int odd = (m + 1) / 2; 
        int even = m - odd; 
        
        long long sum = 0;
        int l = n - 1; 
        
        // On odd days, gain the weight of the heaviest pizza among 4
        for (int i = 0; i < odd; i++) {
            sum += p[l]; 
            l--; // Move left
        }
        
        // On even days, we gain the weight of the second heaviest pizza
        for (int i = 0; i < even; i++) {
            l--; 
            sum += p[l];  // taking 2nd largest wt
            l--; // Move left again
        }
        
        return sum; 
    }
};