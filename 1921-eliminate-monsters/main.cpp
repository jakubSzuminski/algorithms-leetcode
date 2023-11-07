class Solution {
public:
    // time complexity: O (n * log(n))
    // we calculate the arrival time for each monster
    // we sort the arrival times in increasing order
    // if the arrival[i] <= i it means that the monster has already passed dist = 0 point

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int ans = 0;

        float arrival[n];
        for (int i = 0; i < n; i++) {
            arrival[i] = (float) dist[i] / speed[i];
        }

        sort(arrival, arrival + n);

        for (int i = 0; i < n; i++) {
            // if arrival time has passed
            if (arrival[i] <= i) {
                break;
            }

            ans++;
        }

        return ans;
    }
};