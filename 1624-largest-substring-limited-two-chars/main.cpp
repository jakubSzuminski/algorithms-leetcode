class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int left[30];
        int right[30];

        for (int i = 0; i < 30; i++) {
            left[i] = 1000;
            right[i] = -1;
        }

        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a'; // char code
            left[c] = min(left[c], i);
            right[c] = max(right[c], i);

            if (right[c] - left[c] == 1)
                ans = max(ans, 0);
            else if (right[c] - left[c] > 0)
                ans = max(ans, right[c] - left[c] - 1);
        }

        return ans;
    }
};