class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        int ans = 0;
        for (auto [_, c] : m) {
            if (c == 1) return -1;
            ans += ceil((double)(c) / 3);
        }

        return ans;
    }
};