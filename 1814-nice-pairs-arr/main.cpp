class Solution {
public:
    int rev(int n) {
        int result = 0;

        while (n) {
            result = result * 10 + n % 10;
            n /= 10;
        }

        return result;
    }
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        int ans = 0;
    
        map<int, int> rev_diffs;
    
        for (int i = 0; i < nums.size(); i++) {
            int rev_diff = nums[i] - rev(nums[i]);

            if (rev_diffs.find(rev_diff) != rev_diffs.end()) {
                ans = (ans + rev_diffs[rev_diff]) % mod;
                rev_diffs[rev_diff]++;
            } else {
                rev_diffs[rev_diff] = 1;
            }
        }

        return ans;
    }
};