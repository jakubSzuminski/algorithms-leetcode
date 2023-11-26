class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            
            vector<int> curr_row = matrix[row];
            sort(curr_row.begin(), curr_row.end(), greater());
            for (int i = 0; i < n; i++) {
                ans = max(ans, curr_row[i] * (i + 1));
            }
        }
        
        return ans;
    }
};