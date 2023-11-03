class Solution {
public:
    // linear time complexity depending on target.size() and n
    // this solution beats 100% of users (runtime)

    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        int i = 0;
        for (int stream = 1; stream <= n; stream++) {
            if (i >= target.size()) {
                break;
            }

            if (target[i] == stream) {
                result.push_back("Push");
                i++;
            } else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }

        return result;
    }
};