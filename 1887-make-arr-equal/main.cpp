class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        int ans = 0;
        int prev_count = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                ans += prev_count;
            } else {
                ans += ++prev_count;
            }
        }

        return ans;
    }
};