class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

       // like column height: height of consective 1's
        vector<int>ht(n, 0); 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) ht[j] = 0; 
                else ht[j]+=1; 
            }
            vector<int>temp = ht; 
            sort(temp.begin(), temp.end()); 
            for(int i=0; i<n; i++){
                ans = max(ans, temp[i]*(n-i));
            }
        }
        return ans; 
    }
};