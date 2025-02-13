class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>>q; 

        for(int i=0; i<n; i++) q.push(nums[i]);
        int cnt =0; 
        while(q.size() >=2){
            if(q.top()>=k) return cnt;

            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            long long num = (long long)min(x, y)*2 + max(x, y);
            q.push(num);
            cnt++; 
        }
        return cnt; 
    }
};