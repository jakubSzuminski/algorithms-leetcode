class Solution {
public:
    // solution is based on the __builtin_popcount which
    // is a GCC-builtin function which counts the number of "1"
    // bits in positive integers

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);

            if (count_a == count_b) return a < b;
            return count_a < count_b;
        });

        return arr;
    }
};