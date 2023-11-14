class Solution {
public:
    // this solution works in linear time (alphabet_size * n)
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }

        int ans = 0;
        for (char letter : letters) {
            int i = -1; // "start" point of the subseq
            int j = 0; // "end" point of the subseq

            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }

                    j = k;
                }
            }

            // how many different characters do we have
            // in between the "start" and "end" point (i, j)
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }

            ans += between.size();
        }

        return ans;
    }
};