class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();

        vector<int>omp(26, 0); 
        vector<int>emp(26, 0); 

        for(int i=0; i<n; i++){
            if(i%2==0) emp[s1[i] - 'a'] ++; 
            else omp[s1[i] - 'a'] ++; 
        } 

        for(int i=0; i<n; i++){
            if(i%2==0) emp[s2[i]- 'a'] --; 
            else omp[s2[i]- 'a'] --;
            
            if(emp[s2[i]- 'a'] < 0) return false; 
            if(omp[s2[i]- 'a'] < 0) return false; 
        } 

        return true; 
    }
};