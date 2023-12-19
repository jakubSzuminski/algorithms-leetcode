class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        if (!img.size()) return {};

        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbors_count = 0;
                int neighbors_sum = 0;

                // go through all the neighbors of the cell (i, j)
                if (i > 0) {
                    neighbors_count++;
                    neighbors_sum += img[i - 1][j];
                }

                if (j > 0) {
                    neighbors_count++;
                    neighbors_sum += img[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    neighbors_count++;
                    neighbors_sum += img[i - 1][j - 1];
                }

                if (i < n - 1) {
                    neighbors_count++;
                    neighbors_sum += img[i + 1][j];
                }

                if (j < m - 1) {
                    neighbors_count++;
                    neighbors_sum += img[i][j + 1];
                }

                if (i < n - 1 && j < m - 1) {
                    neighbors_count++;
                    neighbors_sum += img[i + 1][j + 1];
                }

                if (i < n - 1 && j > 0) {
                    neighbors_count++;
                    neighbors_sum += img[i + 1][j - 1];
                }

                if (j < m - 1 && i > 0) {
                    neighbors_count++;
                    neighbors_sum += img[i - 1][j + 1];
                }

                // include itself
                neighbors_count++;
                neighbors_sum += img[i][j];

                result[i][j] = neighbors_sum / neighbors_count;
            }

        }

        return result;
    }
};