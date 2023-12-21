class Solution {
public:
    struct {
        bool operator()(const vector<int> a, const vector<int> b) {
            return a[0] < b[0];
        }
    } compare;

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);

        int max_gap = 0;

        for (int i = 1; i < points.size(); i++) {
            max_gap = max(points[i][0] - points[i - 1][0], max_gap);
        }

        return max_gap;
    }
};