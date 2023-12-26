class Solution {
public:
    const int mod = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        for (int jump = 1; jump <= k && jump <= target; jump++) {
            dp[1][jump] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int jump = 1; jump <= k && j + jump <= target; jump++) {
                    dp[i + 1][j + jump] = (dp[i + 1][j + jump] + dp[i][j]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};