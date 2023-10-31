class Solution {
public:
    // we're using the fact that the operation
    // reverse to XOR is XOR itself
    // so we can iterate through the prefixes
    // and reverse-engineer the array with XOR
    // operations

    // time complexity: O(n);
    // space complexity: O(n);

    vector<int> findArray(vector<int>& pref) {
        if (pref.size() == 0) {
            return {};
        }

        vector<int> arr;
        arr.push_back(pref[0]);

        for (int i = 1; i < pref.size(); i++) {
            arr.push_back(pref[i - 1] ^ pref[i]);
        }

        return arr;
    }
};