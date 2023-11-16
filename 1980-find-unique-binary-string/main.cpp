class Solution {
public:
    // approach:
    // 1. convert all the binary strings to ints
    // 2. as we know, the "n" bits can represent a certain range (0, x) of numbers
    // 3. we can iterate through all the numbers in the range
    // and if a certain number does not exist there, it was not represented
    // in the original vector nums (thus, we have our solution)
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> ints;

        for (int i = 0; i < n; i++) {
            ints.insert(stoi(nums[i], 0, 2));
        }

        for (int num = 0; num <= n; num++) {
            if (ints.find(num) == ints.end()) {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }

        return "";
    }
};