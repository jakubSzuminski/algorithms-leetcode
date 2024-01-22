class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int missing = -1;
        int twice = -1;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && nums[i] == nums[i + 1]) {
                twice = nums[i];
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!binary_search(nums.begin(), nums.end(), i)) {
                missing = i;
                break;
            }
        }

        return { twice, missing };
    }
};