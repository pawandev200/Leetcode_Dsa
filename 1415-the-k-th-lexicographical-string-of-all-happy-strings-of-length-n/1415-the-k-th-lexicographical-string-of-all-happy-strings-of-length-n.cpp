class Solution {
public:
    
    // String is constructed in lexicographically smallest order: 
    // if we construct the string of size n then need to dec the cnt by one 
    // each time if k ==0 means it is the kth smallest lexicographically string

    void solve(int i, int n, int cnt, string &temp, vector<string> &ans){
        //base case: 
        if(i == n){ // found a new candidate, but is this kth string
            // dec cnt globally(by &) to find the kth string from list
            // if(--cnt ==0) ans = temp; // without storing all strings
            ans.push_back(temp);  // by storing 
            return; 
        }
        for(char ch = 'a'; ch<='c'; ch++){
            if(temp.empty() || temp.back()!=ch){
                temp.push_back(ch);
                solve(i+1, n, cnt, temp, ans);
                temp.pop_back();
                // if(cnt == 0) return; 
            }
        }
    }
    string getHappyString(int n, int k) {
        string temp; 
        // string ans="";
        vector<string>ans;  
        solve(0, n, k, temp, ans);
        return k <= ans.size() ? ans[k - 1] : "";
    }
};