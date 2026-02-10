class Solution {
public:
    bool isBalanced(vector<int>&freq, int t){
        for(int f: freq){
            if(f!=0 && f!=t) return false; 
        }
        return true; 
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;  
        for(int i=0; i<n; i++){
            vector<int>freq(26, 0);
            int temp = 0; 
            for(int j = i; j<n; j++){
                freq[s[j] - 'a']++; 
                if(isBalanced(freq, freq[s[j] - 'a'])) temp = max(temp, j-i+1);
            }
            ans = max(ans, temp);
        }
        return ans; 
    }
};