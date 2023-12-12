class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxA = 0;
        int maxB = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxA) {
                maxB = maxA;
                maxA = nums[i];
            } else if (nums[i] > maxB) {
                maxB = nums[i];
            }
        }

        return (maxA - 1) * (maxB - 1);
    }
};