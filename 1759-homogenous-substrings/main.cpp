class Solution {
public:
    const int mod = 1e9 + 7;

    // this solution works in linear time
    // depending on the length of the string
    int countHomogenous(string s) {
        int ans  = 0;
        int current_streak = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i-1]) {
                current_streak++;
            } else {
                current_streak = 1;
            }

            ans = (ans + current_streak) % mod;
        }

        return ans % mod;
    }
};