class Solution {
public:
    int totalMoney(int n) {
        int ans = 1;

        int dp[n + 1];
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            if (i >= 7 && i % 7 == 0) dp[i] = dp[i - 7] + 1;
            else dp[i] = dp[i - 1] + 1;

            ans += dp[i];
        }

        return ans;
    }
};