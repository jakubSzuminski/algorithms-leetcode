class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> m_a(26, 0);
        vector<int> m_b(26, 0);

        for (int i = 0; i < word1.size(); i++) {
            m_a[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.size(); i++) {
            m_b[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((m_a[i] == 0 && m_b[i] != 0) || (m_a[i] != 0 && m_b[i] == 0))
                return false;
        }

        sort(m_a.begin(), m_a.end());
        sort(m_b.begin(), m_b.end());

        for (int i = 0; i < 26; i++) {
            if (m_a[i] != m_b[i])
                return false;
        }

        return true;
    }
};