class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int>maxheap;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                maxheap.push(matrix[i][j]);

                if(maxheap.size() > k) maxheap.pop();
            }
        }
        return maxheap.top();  
    }
};