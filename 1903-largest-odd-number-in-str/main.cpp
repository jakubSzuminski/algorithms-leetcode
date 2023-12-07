class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1;

        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit % 2) {
                last = i;
                break;
            }
        }

        string result = "";
        for (int i = 0; i <= last; i++) {
            result += num[i];
        }

        return result;
    }
};