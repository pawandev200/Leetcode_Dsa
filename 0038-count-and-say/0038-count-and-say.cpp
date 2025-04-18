class Solution {
public:
    string solve(string s) {
        stack<char> st;
        int cnt = 0;
        string ans = "";   

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() != s[i]) {
                ans += to_string(cnt);
                ans += st.top();
                cnt = 0;
                while (!st.empty()) st.pop();
            }
            if (st.empty() || st.top() == s[i]) {
                cnt++;
                st.push(s[i]);
            }
        }

        // Add the last group after the loop ends
        if (!st.empty()) {
            ans += to_string(cnt);
            ans += st.top();
        }

        return ans;
    }

    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            s = solve(s);
        }
        return s;
    }
};
