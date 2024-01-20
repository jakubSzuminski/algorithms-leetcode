class Solution {
public:
    int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        long ans = 0;
        stack<int> s;

        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == a.size() || a[s.top()] >= a[i])) {
                int mid = s.top(); s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;

                long count = (mid - left) * (right - mid) % mod;
                ans = (ans + (count * a[mid]) % mod) % mod;
            }

            s.push(i);
        }

        return static_cast<int>(ans);
    }
};