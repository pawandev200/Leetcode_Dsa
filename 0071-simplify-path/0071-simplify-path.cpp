class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();
        string ans, dir;

        for(int i = 0; i < n; i++) {
            if (path[i] == '/' || i == n - 1) {
                if (i == n - 1 && path[i] != '/') dir += path[i]; 

                if (dir == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else if (!dir.empty() && dir != ".") {
                    stack.push_back(dir);
                }
                dir.clear();
            } else {
                dir += path[i];
            }
        }

        for (string &s : stack) ans += "/" + s;
        return ans.empty() ? "/" : ans;
    }
};
