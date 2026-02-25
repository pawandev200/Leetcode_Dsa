class Solution {
public:
    static bool compare(int a, int b) {
        
        int bitCountA = __builtin_popcount(a); // # of set bits (1s)
        int bitCountB = __builtin_popcount(b);

        if (bitCountA == bitCountB) return a < b;
        
        // Sort by the number of set bits in ascending order
        return bitCountA < bitCountB;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        // Use the compare function to sort the vector
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};