class Solution {
public:
    long math(int a, int b, char sign) {
        if (sign == '+') return a + b;
        if (sign == '-') return a - b;
        if (sign == '*') return (long) a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            if (tokens[i].size() == 1 and tokens[i][0] < 48) {
                long b = s.top();
                s.pop();
                long a = s.top();
                s.pop();

                s.push(math(a, b, tokens[i][0]));
            } else {
                s.push(stol(tokens[i]));
            }
        }

        return s.top();
    }
};