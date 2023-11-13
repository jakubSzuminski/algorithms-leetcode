class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels_set = {'a', 'e', 'i', 'o', 'u'};
        vector<char> vowels;

        for (int i = 0; i < s.size(); i++) {
            if (vowels_set.find(tolower(s[i])) != vowels_set.end()) {
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowels_set.find(tolower(s[i])) != vowels_set.end()) {
                s[i] = vowels[j++];
            }
        }

        return s;
    }
};