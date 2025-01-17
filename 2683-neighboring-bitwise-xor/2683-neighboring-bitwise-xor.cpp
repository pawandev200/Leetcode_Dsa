class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorSum = 0;
        for (int num : derived) {
            xorSum ^= num; // XOR all elements
        }
        return xorSum == 0; // Check if XOR sum is 0
    }
};
