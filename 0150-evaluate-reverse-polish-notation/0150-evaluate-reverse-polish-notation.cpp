class Solution {
public:
    int getval(string &f){
        int ans = 0; 
        for(int i=0; i<f.size(); i++){
            ans=ans*10 + (f[i]-'0');
        }
        return ans; 
    }
    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(t[i] =="+" || t[i] =="-" || t[i] =="*" || t[i] =="/"){
                if(!st.empty()){
                    int f = st.top(); st.pop();
                    int s = st.top(); st.pop();
                    int ans = 0;
                    if (t[i] == "+") ans = s + f;
                    else if (t[i] == "-") ans = s - f;
                    else if (t[i] == "*") ans = s * f;
                    else if (t[i] == "/") ans = s / f;
                    st.push(ans);
                }
            }
            else st.push(stoi(t[i]));
        }
        return st.top(); 
    }
};