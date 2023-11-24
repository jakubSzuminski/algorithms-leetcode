class Solution {
public:
    // the method is the following:
    // group into triplets: [max, max - 1, smallest]
    // - Alice gets the max
    // - we get the max - 1
    // - Bob gets the smalles
    // after we sort the piles, we can easily calculate the ans in O(n)
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int ans = 0;
        int bottom = 0;
        for (int i = piles.size() - 2; i >= bottom; i -= 2) {
            ans += piles[i];
            bottom++;
        }

        return ans;
    }
};