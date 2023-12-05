class Solution {
public:
    int numberOfMatches(int teams) {
        int games = 0;

        while (teams > 1) {
            if (teams % 2) {
                games += (teams - 1) / 2;
                teams = (teams - 1) / 2 + 1;
            } else {
                games += teams / 2;
                teams /= 2;
            }
        }

        return games;
    }
};