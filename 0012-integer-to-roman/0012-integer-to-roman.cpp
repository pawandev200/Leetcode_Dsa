class Solution {
public:
    string intToRoman(int num) {
        //mapping: direct and Subtractive form(4... 9...).
        vector<pair<int, string>> mp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        // Iterating through the mapping and subtracting values while appending symbols.
        for (auto &[val, symb] : mp) {
            while (num >= val) {
                result += symb;
                num -= val;
            }
        }

        return result;
    }
};
