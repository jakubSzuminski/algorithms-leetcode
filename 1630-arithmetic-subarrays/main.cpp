class Solution {
public:
    bool solve(vector<int> nums) {
        sort(nums.begin(), nums.end());

        int diff = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != diff) return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // observation: an "arithmetic" array has to be sorted

        vector<bool> ans(l.size(), false);
        for (int i = 0; i < l.size(); i++) {
            // create a subarray (l, r)
            vector<int> subarr;
            for (int j = l[i]; j <= r[i]; j++) {
                subarr.push_back(nums[j]);
            }

            // solve for a each testcase with a subarray (l, r)
            ans[i] = solve(subarr);
        }

        return ans;
    }
};