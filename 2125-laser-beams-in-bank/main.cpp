class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> c;

        for (int i = 0; i < bank.size(); i++) {
            int count = 0;

            for (int j = 0; j < bank[i].size(); j++) {
                count += (bank[i][j] == '1' ? 1 : 0);
            }

            if (count > 0) c.push_back(count);
        }

        int ans = 0;
        for (int i = 1; i < c.size(); i++) {
            ans += (c[i] * c[i - 1]);
        }

        return ans;
    }
};