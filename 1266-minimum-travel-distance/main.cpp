class Solution {
public:
    int point_distance(int x_from, int y_from, int x_to, int y_to) {
        bool x_up = x_to > x_from;
        bool y_up = y_to > y_from;

        int dist = 0;

        // 1. move diagonally first
        while (
            (x_up ? (x_from < x_to) : (x_from > x_to)) &&
            (y_up ? (y_from < y_to) : (y_from > y_to))
        ) {
            x_from += x_up ? 1 : -1;
            y_from += y_up ? 1 : -1;
            dist++;
        }

        // 2. move in x later
        while (x_up ? (x_from < x_to) : (x_from > x_to)) {
            x_from += x_up ? 1 : -1;
            dist++;
        }

        // 3. move in y later
        while (y_up ? (y_from < y_to) : (y_from > y_to)) {
            y_from += y_up ? 1 : -1;
            dist++;
        }

        return dist;
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for (int i = 1; i < points.size(); i++) {
            ans += point_distance(
                points[i - 1][0], points[i - 1][1],
                points[i][0], points[i][1]
            );
        }

        return ans;
    }
};