class Solution {
public:
    const int mod = 1e9 + 7;
    int m, n;
    unordered_map<string, int> memo;

    bool isValidRow(const vector<int>& row) {
        for (int i = 1; i < row.size(); ++i)
            if (row[i] == row[i - 1])
                return false;
        return true;
    }

    bool isValidCol(const vector<int>& prevRow, const vector<int>& currRow) {
        for (int i = 0; i < prevRow.size(); ++i)
            if (prevRow[i] == currRow[i])
                return false;
        return true;
    }

    void generateRows(vector<vector<int>>& validRows, vector<int>& row, int col) {
        if (col == n) {
            if (isValidRow(row))
                validRows.push_back(row);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (col > 0 && row[col - 1] == color) continue;
            row[col] = color;
            generateRows(validRows, row, col + 1);
        }
    }

    int dp(int i, const vector<int>& prevRow, const vector<vector<int>>& validRows) {
        if (i == m) return 1;
        
        string key = to_string(i) + "-";
        for (int c : prevRow) key += to_string(c);
        if (memo.count(key)) return memo[key];

        int total = 0;
        for (const auto& row : validRows) {
            if (isValidCol(prevRow, row)) {
                total = (total + dp(i + 1, row, validRows)) % mod;
            }
        }
        return memo[key] = total;
    }

    int colorTheGrid(int m_, int n_) {
        m = m_;
        n = n_;
        
        vector<vector<int>> validRows;
        vector<int> row(n);
        generateRows(validRows, row, 0);

        vector<int> emptyRow(n, -1); // Start with no row above
        return dp(0, emptyRow, validRows);
    }
};
