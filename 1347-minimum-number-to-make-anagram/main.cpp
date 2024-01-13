class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sc(30, 0);
        vector<int> st(30, 0);

        for (int i = 0; i < s.size(); i++) {
            sc[s[i] - 'a']++;
            st[t[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 30; i++) {
            ans += abs(st[i] - sc[i]);
        }

        return ans / 2;
    }
};