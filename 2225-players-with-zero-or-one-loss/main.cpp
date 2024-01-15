class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;

        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (losses.find(loser) != losses.end()) {
                losses[matches[i][1]]++;
            } else {
                losses[matches[i][1]] = 1;
            }

            if (losses.find(winner) == losses.end()) {
                losses[winner] = 0;
            }
        }

        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});

        for (auto [player, losses] : losses) {
            if (losses == 0) {
                ans[0].push_back(player);
            } else if (losses == 1) {
                ans[1].push_back(player);
            }
        }

        return ans;
    }
};