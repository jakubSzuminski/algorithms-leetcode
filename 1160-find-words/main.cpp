class Solution {
public:
    int n = 29;

    int solve(vector<int> available, string word) {
        for (int i = 0; i < word.size(); i++) {
            short char_code = word[i] - 'a';
            if (--available[char_code] < 0) {
                return 0;
            }
        }

        return word.size();
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> available(n, 0);

        for (int i = 0; i < chars.size(); i++) {
            available[chars[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            ans += solve(available, words[i]);
        }

        return ans;
    }
};