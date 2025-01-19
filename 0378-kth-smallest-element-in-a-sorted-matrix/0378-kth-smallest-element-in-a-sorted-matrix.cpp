class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min-heap to store values and their coordinates
        using piii = pair<int, pair<int, int>>;
        priority_queue<piii, vector<piii>, greater<piii>> minheap;

        // Push the first element of each row into the heap
        for (int i = 0; i < n; i++) {
            minheap.push({matrix[i][0], {i, 0}});
        }

        // Extract the smallest element from the heap k times
        while (!minheap.empty()) {
            auto [val, indices] = minheap.top();
            minheap.pop();
            k--;
            if (k == 0) return val; // Return the kth smallest element

            int row = indices.first;
            int col = indices.second;

            // Push the next element in the same row into the heap
            if (col + 1 < n) {
                minheap.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return -1; // This line should not be reached
    }
};
