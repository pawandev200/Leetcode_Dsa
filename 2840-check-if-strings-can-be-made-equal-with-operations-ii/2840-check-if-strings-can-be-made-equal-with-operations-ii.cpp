class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        unordered_map<char, int>omp; 
        unordered_map<char, int>emp;

        for(int i=0; i<n; i++){
            if(i%2==0) emp[s1[i]] ++; 
            else omp[s1[i]] ++; 
        } 

        for(int i=0; i<n; i++){
            if(i%2==0) emp[s2[i]] --; 
            else omp[s2[i]] --;
            if(emp[s2[i]] < 0) return false; 
            if(omp[s2[i]] < 0) return false; 
        } 

        return true; 
    }
};