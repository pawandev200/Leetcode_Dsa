class Solution {
public:
    int solve(vector<int>&freq){
        int ans = 0; 
        for (int i = 0; i < 26; ++i){
            if (freq[i] > 0) {
                freq[i]--; 
                ans+=1+solve(freq);
                freq[i]++;
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