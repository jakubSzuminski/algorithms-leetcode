class Solution {
public:
    // mathematical solution based on logarithms
    // time complexity: O(1)
    // space complexity: O(1)
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;

        // using the "change-of-base" formula for logarithms
        // we will calculate the logarithm of base 4
        // http://dl.uncw.edu/digilib/Mathematics/Algebra/mat111hb/EandL/logprop/logprop.html
        double lg = log(n) / log(4);

        // if the result is an integer, n is the power of 4
        return lg == (int) lg;
    }
}