class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());

        nums.push_back(800);
        vector<vector<int>> result;
        int left = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i] && left == -1) {
                left = i - 1;
            } else if (nums[i - 1] != nums[i]){
                int count = i - left;

                while (result.size() < count) {
                    result.push_back({});
                }

                int j = 0;
                while (j < count) {
                    result[j].push_back(nums[i - 1]);
                    j++;
                }

                left = i;
            }
        }

        return result;
    }
};