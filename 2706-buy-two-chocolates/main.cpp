class Solution {
public:
    // problem: looking for 2 smallest numbers in the prices
    // array and returning a certain result based on that
    int buyChoco(vector<int>& prices, int money) {
        int min_a = 1000; // lower of the prices
        int min_b = 1000; // second minimum of the prices

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_a) {
                min_b = min_a;
                min_a = prices[i];
            } else if (prices[i] < min_b) {
                min_b = prices[i];
            }
        }

        if (min_a + min_b > money)
            return money;

        return money - min_a - min_b;
    }
};