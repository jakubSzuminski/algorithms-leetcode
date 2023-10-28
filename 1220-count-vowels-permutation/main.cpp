class Solution {
public:
    // simple vowel -> number mapping
    // for simplification
    static const int a = 0,
        e = 1,
        i = 2,
        o = 3,
        u = 4;

    // approach is based on dynamic programming
    // the prev & current arrays hold the number of possible
    // combinations for particular vowels
    // time complexity: o(n)
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;

        int prev[5];
        int current[5];

        for (int i = 0; i < 5; i++) {
            prev[i] = 1;
            current[i] = 1;
        }

        for (int j = 1; j < n; j++) {
            current[e] = prev[a];
            current[e] = (current[e] + prev[i]) % mod;

            current[a] = prev[e];
            current[a] = (current[a] + prev[u]) % mod;
            current[a] = (current[a] + prev[i]) % mod;

            current[i] = prev[e];
            current[i] = (current[i] + prev[o]) % mod;

            current[u] = prev[o];
            current[u] = (current[u] + prev[i]) % mod;

            current[o] = prev[i];

            for (int z = 0; z < 5; z++) {
                prev[z] = current[z];
            }
        }

        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + current[i]) % mod;
        }

        return ans;
    }
};