class Solution {
public:
    void solve(int i, int n, int &k, string &temp, string &ans){
        // base case: 
        if(k==0) return; 
        if(i==n){
            k--; 
            if(k==0) ans = temp; 
            return; 
        }
        for(char ch='a'; ch<='c'; ch++){
            if(temp.empty() || temp.back()!=ch){
                temp.push_back(ch);
                solve(i+1, n, k, temp, ans);
                temp.pop_back();
            }
        }
        // return; 
    }
    string getHappyString(int n, int k) {
        string temp; 
        string ans = ""; 

        solve(0, n, k, temp, ans);
        return ans; 
    }
};