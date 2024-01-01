class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int ans = 0;
        int j = g.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (j < 0) return ans;
            if (s[i] >= g[j--]) {
                ans++;
            } else {
                i++;
            }
        }

        return ans;
    }
};