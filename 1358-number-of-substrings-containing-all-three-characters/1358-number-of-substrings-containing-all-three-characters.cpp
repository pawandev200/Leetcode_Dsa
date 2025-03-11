class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i =0; 
        int j =0; 
        int cnt =0;
        unordered_map<char, int>mp;  
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>=3){
               cnt+=n-j; 
               mp[s[i]]--; 
               if(mp[s[i]] ==0) mp.erase(s[i]);
               i++;
            } 
            j++; 
        }
        return cnt; 
    }
};