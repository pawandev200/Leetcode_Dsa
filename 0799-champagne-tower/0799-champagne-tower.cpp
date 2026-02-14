class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<vector<double>> tower(qr + 1, vector<double>(qr + 1, 0.0));
        tower[0][0] = static_cast<double>(poured);

        for (int row = 0; row < qr; row++) {
            for (int glass = 0; glass <= row; glass++) {
                double excess = (tower[row][glass] - 1.0) / 2.0;
                if (excess > 0) {
                    tower[row + 1][glass] += excess;
                    tower[row + 1][glass + 1] += excess;
                }
            }
        }

        return min(1.0, tower[qr][qg]);
    }
};