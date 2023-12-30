class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int char_count[30];
        for (int i = 0; i < 30; i++)
            char_count[i] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < words[i].size(); j++)
                char_count[words[i][j] - 'a']++;

        for (int i = 0; i < 30; i++)
            if (char_count[i] % n != 0)
                return false;

        return true;
    }
};