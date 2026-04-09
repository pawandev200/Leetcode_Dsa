class Solution {
public:
    // den = 1 to n
    // num = 1 to n-1  ajdust in such a way so fraction: (0, 1)
    vector<string> simplifiedFractions(int n) {
        if(n <= 1) return {" "};
        vector<string>ans; 
        for(int i=1; i<n; i++){ // num
            for(int j = i+1; j<=n; j++){ // den
                if(__gcd(i, j)==1){ // gcd simplified the frac,make it unique
                    string num = to_string(i);
                    string den = to_string(j);
                    ans.push_back(num + "/" + den);
                }
            }
        }
        return ans; 
    }
};