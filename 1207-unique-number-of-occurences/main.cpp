class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i]) != m.end()) {
                m[arr[i]]++;
            } else {
                m[arr[i]] = 1;
            }
        }

        unordered_set<int> vals;
        for (auto [k, v] : m) {
            if (vals.find(v) != vals.end()) return false;
            vals.insert(v);
        }

        return true;
    }
};