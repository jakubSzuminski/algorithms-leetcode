class Solution {
public:
    // approach:
    // 1. sort the array
    // 2. for each element in nums analyze their maximum frequency
    //    - by itearting through all the smaller elements
    //    - until the k operations are made
    //    - and update the score (ans) based on the max frequency
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        sort(nums.begin(), nums.end());

        int target;
        int k_tmp = k;
        int ans_tmp = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == target) {
                ans_tmp++;
                ans = max(ans, ans_tmp);
                continue;
            }

            target = nums[i];
            k_tmp = k;
            ans_tmp = 1;

            for (int j = i - 1; j >= 0 && k_tmp > 0; j--) {
                int smaller = nums[j];
                if (target - smaller > k_tmp) {
                    ans = max(ans, ans_tmp);
                    break;
                } else {
                    ans_tmp++;
                    k_tmp -= (target - smaller);
                    ans = max(ans, ans_tmp);
                }
            }

            ans = max(ans, ans_tmp);
        }

        return ans;
    }
};