class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 100 * 100 * 100 + 5;
            }
        }

        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
            if (n == 1) ans = min(ans, dp[0][i]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int current = matrix[i][j];

                if (j > 0 && (dp[i - 1][j - 1] + current) < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + current;
                }

                if (j < n && (dp[i - 1][j + 1] + current) < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j + 1] + current;
                }

                if ((dp[i - 1][j] + current) < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j] + current;
                }

                if (i == n - 1) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};