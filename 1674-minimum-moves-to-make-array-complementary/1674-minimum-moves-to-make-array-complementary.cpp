class Solution {
public:
    int minMoves(vector<int>& nums, int lim) {
        int n = nums.size(); // even len

        // tar sum range: [2, 2*lim] and for each target, 0, 1 or 2 moves possible
        // intially assume all have 2 moves, and decrease at specific range: 
        // 0 move -> cs ==t 
        // 1 move -> [1+min(a, b), lim + max(a, b)] out side of range is 2

        vector<int>pdiff(2*lim+2, 0);
        for(int i=0; i<n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];

            int mx = max(a, b);
            int mn = min(a, b);
            int cs = a + b; 

            pdiff[2]+=2;  // 2 everywhere in range: 2 - 2*lim
            pdiff[1+mn] -=1; // 1 move interval

            pdiff[cs] -=1;  // exact match 0 move
            pdiff[cs+ 1] +=1;  // 1 move interval back 

            pdiff[lim+mx+1] +=1;  // 2 moves back 
        }

        int mini = INT_MAX;
        int curr = 0; 
        for(int i=2; i<=2*lim; i++){
            curr+=pdiff[i];
            mini = min(mini, curr);
        }

        return mini; 
    }
};