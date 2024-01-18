class Solution {
public:
    int climbStairs(int n) {
        int pre_last_step = 1;
        int last_step = 1;

        for (int i = 2; i <= n; i++) {
            int current_step = 0;
            current_step += pre_last_step;
            current_step += last_step;

            pre_last_step = last_step;
            last_step = current_step;
        }

        return last_step;
    }
};