class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        vector<int> suffix(s.size() + 1, 0);

        for (int i = s.size() - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        for (int i = s.size() - 1; i > 0; i--) {
            int left = i - (suffix[0] - suffix[i]);
            ans = max(ans, left + suffix[i]);
        }

        return ans;
    }
};