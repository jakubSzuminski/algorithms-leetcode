class Solution {
public:
    const int MOD = 1e9 + 7;

    int count(int index, int seats, string& corridor, int cache[][3]) {
        if (index == corridor.length()) {
            return seats == 2 ? 1 : 0;
        }

        if (cache[index][seats] != -1) {
            return cache[index][seats];
        }

        // Result of the sub-problem
        int result = 0;

        if (seats == 2) {
            if (corridor[index] == 'S') {
                result = count(index + 1, 1, corridor, cache);
            } else {
                // If the current element is "P", then we have two options
                // 1. Close the section and start a new section from this index
                // 2. Keep growing the section
                result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;  
            }
        } else {
            // Keep growing the section. Increment "seats" if present
            // element is "S"
            if (corridor[index] == 'S') {
                result = count(index + 1, seats + 1, corridor, cache);
            } else {
                result = count(index + 1, seats, corridor, cache);
            }
        }

        cache[index][seats] = result;
        return cache[index][seats];
    }

    int numberOfWays(string corridor) {
        int cache[corridor.length()][3];
        memset(cache, -1, sizeof(cache));

        return count(0, 0, corridor, cache);
    }
};