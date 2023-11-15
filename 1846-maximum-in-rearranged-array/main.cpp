class Solution {
public:
    // the result array will always be sorted (non-decreasing order)
    // the maximum array is always in form: [1, 2, 3, ..., n - 1, n]
    // but we can't increase elements, we can only decrease them so it can look:
    // like this: [1, 2, 2, 2, 3, ..., n - 1, n]

    // so: if the condition of abs(next - prev) >= 1 is not met,
    // set the next to prev + 1, otherwise leave it as it is
    // (because we can't increase it)
    // the last element in our sorted array will be the maximum
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // 1. let's sort the array
        sort(arr.begin(), arr.end());

        if (!arr.size()) {
            return 0;
        }

        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr[arr.size() - 1];
    }
};