class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = 0;

        for (int i = 2; i <= n; i++) {
            short prev = s[i - 2] - '0';
            short current = s[i - 1] - '0';

            if (current != 0) {
                dp[i] += dp[i - 1];
            }

            if ((prev == 1) || (prev == 2 && current <= 6)) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};