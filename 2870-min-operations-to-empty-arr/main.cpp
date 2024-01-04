class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        int ans = 0;
        for (auto i : m) {
            int count = i.second;

            if (count % 3 == 0) {
                ans += count / 3;
                continue;
            }

            while (count > 4) {
                count -= 3;
                ans++;
            }

            if (count % 2 == 0) {
                ans += count / 2;
                continue;
            }

            return -1;
        }

        return ans;
    }
};