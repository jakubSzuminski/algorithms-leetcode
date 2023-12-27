class Solution {
public:
    int remove_from_range(const vector<int>& time, const int left, const int right) {
        int sum = 0;
        int max_time = 0;

        for (int i = left; i <= right; i++) {
            sum += time[i];
            max_time = max(max_time, time[i]);
        }

        return sum - max_time;
    }

    int minCost(string colors, vector<int>& time) {
        int ans = 0;
        int left = -1;

        for (int i = 0; i < time.size(); i++) {
            char color = colors[i];
            if (left == -1) {
                left = i;
            } else if (i > 0 && colors[i] != colors[i - 1]){
                ans += remove_from_range(time, left, i - 1);
                left = i;
            } else if (i == time.size() - 1) {
                ans += remove_from_range(time, left, i);
            }
        }

        return ans;
    }
};