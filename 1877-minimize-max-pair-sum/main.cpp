class Solution {
public:
    // 1. we sort the numbers - O(n log n)
    // 2. we pair up the numbers (i, n - i) [the smallest with the biggest]
    // as that approach minimizes the maximum pair sum
    // 3. we update ans = max(ans, new_pair_sum);
    // 4. we return the ans

    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }

        return ans;
    }
};