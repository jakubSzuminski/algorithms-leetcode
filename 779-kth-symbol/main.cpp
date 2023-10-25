class Solution {
public:
    // recursive solution
    // time complexity: O(n)
    // space complexity: O(n) [recursive stack]
    int kthGrammar(int n, int k) {
        // first row only has '0'
        if (n == 1) {
            return 0;
        }

        int total = pow(2, (n - 1)); // number of elements
        int half = total / 2; // middle index

        // if the target is present in the right half,
        // see what is the respective left half symbol
        if (k > half) {
            return 1 - kthGrammar(n, k - half);
        }

        return kthGrammar(n - 1, k);
    }
};