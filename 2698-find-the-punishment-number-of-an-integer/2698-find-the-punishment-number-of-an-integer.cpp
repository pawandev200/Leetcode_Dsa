class Solution {
public:
    // trying out all the partitions and check for the condition: 
    bool solve(int i, int t, string s){
        if(i==s.size()) return t==0; 

        int sum =0; 
        for(int c = i; c<s.size(); c++){ // trying all possible partition: 
            sum = sum*10 + (s[c]-'0');
            if(sum > t) break; 
            if(solve(c+1, t-sum, s)) return true; 
        }
        return false; 
    }

    int punishmentNumber(int n) {
        // given conditions: 
        //1. punishment number: i*i : 1<=i<=n
        //2. partition of x(=i*i): recursive function for it. 

        if(n ==0) return 0;
        int ans = 0;        
        for(int i=1; i<=n; i++){
            int x = i*i;
            string s = to_string(x); 
            if(solve(0, i, s)==true) ans+=x; 
        }
        return ans; 
    }
};