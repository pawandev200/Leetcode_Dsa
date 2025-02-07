class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int>ans(q, 0);
        unordered_map<int, int>ball;
        unordered_map<int, int>color; // color, num of balls
        int i =0;  
        for(auto it:queries){
            int b = it[0];
            int c = it[1];
            if(ball.find(b) !=ball.end()){ // if ball is already colored
                int c0 = ball[b];
                if(--color[c0] ==0) color.erase(c0); // removing extra count
            }
            ball[b] = c; // coloring the ball with new color 
            color[c]++; 
            ans[i++] = color.size();
        }
        return ans; 
    }
};