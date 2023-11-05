class Solution {
public:

    // if k is higher than the array size, we return the max element of an array
    // otherwise, we simulate the game with a queue

    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        int arr_max = 0;

        for (int i = 0; i < arr.size(); i++) {
            arr_max = max(arr_max, arr[i]);
            if (i > 0) q.push(arr[i]);
        }

        if (k >= arr.size()) {
            return arr_max;
        }

        int first = arr[0];
        int times_won = 0;

        while (!q.empty()) {
            int opponent = q.front();
            q.pop();

            if (first > opponent) {
                q.push(opponent);
                times_won++;
            } else {
                q.push(first);
                first = opponent;
                times_won = 1;
            }

            if (times_won == k || first == arr_max) {
                return first;
            }
        }

        return first;
    }
};