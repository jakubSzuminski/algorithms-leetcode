class Solution {
public:
    string largestGoodInteger(string num) {
        if (!num.size()) return "";

        int streak_count = 0;
        int ans = -1;

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1]) {
                streak_count++;

                if (streak_count == 2) {
                    ans = max(ans, num[i] - '0');
                }
            } else {
                streak_count = 0;
            }
        }

        string result = "";

        if (ans != -1) {
            result += (ans + '0');
            result += (ans + '0');
            result += (ans + '0');
        }

        return result;
    }
};