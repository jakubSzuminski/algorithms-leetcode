class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp_distanced(n + 1, 0);
        vector<int> dp_include_last(n + 1, 0);

        dp_distanced[0] = 0;
        dp_include_last[0] = nums[0];

        for (int i = 1; i < n; i++) {
            dp_include_last[i] = nums[i] + dp_distanced[i - 1];
            dp_distanced[i] = max(dp_include_last[i - 1], dp_distanced[i - 1]);
        }

        return max(dp_include_last[n - 1], dp_distanced[n - 1]);
    }
};