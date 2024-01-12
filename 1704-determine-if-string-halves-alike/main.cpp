class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        vector<int> left(30, 0);
        vector<int> right(30, 0);

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                left[tolower(s[i]) - 'a']++;
            } else {
                right[tolower(s[i]) - 'a']++;
            }
        }

        string vowels = "aeiou";
        for (int i = 0; i < vowels.size(); i++) {
            int index = tolower(vowels[i]) - 'a';
            if (left[index] != right[index]) return false;
        }

        return true;
    }
};