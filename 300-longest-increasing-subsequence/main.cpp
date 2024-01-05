class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> a;
        a.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > a.back()) {
                a.push_back(nums[i]);
            } else {
                int low = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();
                a[low] = nums[i];
            }
        }

        return a.size();
    }
};