class Solution {
public:
    bool canConstruct(string rn, string mag) {
        int n = rn.size();
        int m = mag.size();

        vector<int>vect1(26); 
        vector<int>vect2(26); 
        for(auto ch: rn) vect1[ch-'a']++;
        for(auto ch: mag) vect2[ch-'a']++;

        for(int i=0; i<26; i++){
            if(vect1[i]!=0 && vect2[i]==0) return false; 
            if(vect1[i] > vect2[i]) return false; 
        }
        return true; 
    }
};