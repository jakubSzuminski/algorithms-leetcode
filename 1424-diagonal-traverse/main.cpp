class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // IMPORTANT PROPRETY TO REMEMBER: row + col -> identifier of the diagonal, it stays constant
        // on each diagonal we have: (row, col), (row + 1, col - 1), (row + 2, col - 2), ...
        // and the row + col sum always stays the same
        // so we can group all the elements based on their row + col sum

        // step 1 - group all the elements based on the diagonal they belong to
        int last_diagonal = 0;
        map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                int d = row + col;

                if (groups.find(d) != groups.end()) {
                    groups[d].push_back(nums[row][col]);
                } else {
                    groups[d] = {nums[row][col]};
                }

                last_diagonal = max(last_diagonal, d);
            }
        }

        // fill in the answer vector based on the diagonals (from 0 till last_diagonal)
        vector<int> ans;
        for (int i = 0; i <= last_diagonal; i++) {
            for (int j = 0; j < groups[i].size(); j++) {
                ans.push_back(groups[i][j]);
            }
        }

        return ans;
    }
};