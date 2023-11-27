class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int mod = 1e9 + 7;

    // from 0 -> 2 (4, 6)
    // from 1 -> 2 (6, 8)
    // from 2 -> 2 (7, 9)
    // from 3 -> 2 (4, 8)
    // from 4 -> 3 (0, 3, 9)
    // from 5 -> 0
    // from 6 -> 3 (0, 1, 7)
    // from 7 -> 2 (2, 6)
    // from 8 -> 2 (1, 3)
    // from 9 -> 2 (2, 4)
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int dp(int remain_moves, int square) {
        if (remain_moves == 0) {
            return 1;
        }

        if (memo[remain_moves][square] != 0) {
            return memo[remain_moves][square];
        }

        int ans = 0;
        for (int next_square : jumps[square]) {
            ans = (ans + dp(remain_moves - 1, next_square)) % mod;
        }

        memo[remain_moves][square] = ans;
        return ans;
    }

    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % mod;
        }
        return ans;
    }
};