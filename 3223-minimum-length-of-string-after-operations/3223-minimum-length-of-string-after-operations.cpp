class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int minus = 0;
        
        // Count the frequency of each character
        vector<int>freq(26);
        for(int i =0; i<n; i++) freq[s[i] - 'a']++; 

        // For each character, remove pairs (if >= 3)
        for(int i=0; i<26; i++){
            while(freq[i] >=3){
                minus+=2; 
                freq[i]-=2; 
            }
        }
        return n - minus; 
    }
};