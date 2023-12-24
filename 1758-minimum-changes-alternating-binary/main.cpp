class Solution {
public:
    int minOperations(string s) {
        int ans_1 = 0;
        int ans_2 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans_1 += (i % 2);
                ans_2 += (i % 2 == 1 ? 0 : 1);
            } else {
                ans_1 += (i % 2 == 1 ? 0 : 1);
                ans_2 += (i % 2);
            }
        }

        return min(ans_1, ans_2);
    }
};