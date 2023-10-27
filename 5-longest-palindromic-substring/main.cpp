class Solution {
public:
    // this uses the "expanding from center" algorithm
    // where we take advantage of the fact that if we have a valid palindrome
    // we only need to look up whether the two characters on the left and right
    // that we're about to add are the same

    // time complexity: O(n^2)

    string longestPalindrome(string s) {
        // a single character can be a center of the palindrome - bAb
        // or two characters can be the center of the palindrome - bAAb
        // that's why we will loop twice and check both scenarios

        const int n = s.size();

        if (n == 0) {
            return "";
        }

        if (n == 1) {
            return string(1, s[0]);
        }

        int ans = 1;
        string ans_str = string(1, s[0]);

        // loop for single-letter centers
        for (int i = 1; i < n; i++) {
            string result(1, s[i]);

            int width = 1;
            int left = i - width;
            int right = i + width;

            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    width++;
                    result = s[left] + result + s[right];
                    if ((width * 2 + 1) > ans) {
                        ans_str = result;
                        ans = width * 2 + 1;
                    }
                } else {
                    break;
                }

                left = i - width;
                right = i + width;
            }
        }

        // loop for double-letter centers
        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i]) {
                continue;
            }

            string result = "";

            int width = 0;
            int left = i - width - 1;
            int right = i + width;

            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    width++;
                    result = s[left] + result + s[right];
                    if ((width * 2 + 2) > ans) {
                        ans_str = result;
                        ans = width * 2 + 2;
                    }
                } else {
                    break;
                }

                left = i - width - 1;
                right = i + width;
            }
        }

        return ans_str;
    }
};