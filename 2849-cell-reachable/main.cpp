class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // conclusion: if we can reach the finish point in min_time
        // then we will be able to reach it in min_time + n where n is a natural number
        // so any t >= min_time should return true
        // the min_time is the minimium distance between the cells
        // the min_time depends on the maximum distance in x or y

        int dx = abs(fx - sx);
        int dy = abs(fy - sy);

        if (dx == 0 && dy == 0 && t == 1) {
            return false;
        }

        return t >= max(dx, dy);
    }
};