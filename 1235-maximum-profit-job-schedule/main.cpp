class Solution {
public:
    int jobScheduling(vector<int>& start_time, vector<int>& end_time, vector<int>& profit) {
        int n = start_time.size();

        vector<vector<int>> job;
        for (int i = 0; i < n; i++) {
            job.push_back({
                start_time[i],
                end_time[i],
                profit[i]
            });
        }

        sort(job.begin(), job.end(), [] (const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int start = job[i][0];
            int end = job[i][1];
            int profit = job[i][2];

            int other_non_conflict = upper_bound(
                job.begin(),
                job.begin() + i,
                start,
                [&](int time, const auto& other_job) -> bool {
                    return time < other_job[1];
                }
            ) - job.begin();

            dp[i + 1] = max(dp[i], dp[other_non_conflict] + profit);
        }

        return dp[n];
    }
};