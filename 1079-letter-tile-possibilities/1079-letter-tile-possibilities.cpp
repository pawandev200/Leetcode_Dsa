class Solution {
public:
    // Start with every unique char, since it is used so decrease its freq by 1
    // and count it for used char, call recursively with remaining freq 
    // lastly backtrack the freq to try other options
    
    int solve(vector<int>&freq){
        int ans = 0; 
        for (int i = 0; i < 26; i++){
            if (freq[i] > 0) {
                freq[i]--;  // currently used char 
                ans += 1 + solve(freq); // for remaining char 
                freq[i]++; // backtrack
            }
        }
        return ans; 
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int>freq(26); 
        for(int i=0; i<n; i++) freq[tiles[i] - 'A']++; 

        return solve(freq);
    }
};