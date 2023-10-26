class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9 + 7;
        const int n = arr.size();
        long long dp[n];

        sort(arr.begin(), arr.end());
        map<int, int> occurences;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            occurences[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] != 0) continue;

                int other = arr[i] / arr[j];
                if (occurences.find(other) != occurences.end()) {
                    dp[i] = (dp[i] + (dp[j] * dp[occurences[other]]) % mod) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};