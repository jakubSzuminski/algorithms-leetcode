class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = {nums[0]};

        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int left_sum = prefix[i] - nums[i];
            int right_sum = prefix[n - 1] - prefix[i];
            
            int left_count = i;
            int right_count = n - 1 - i;
            
            int left_total = left_count * nums[i] - left_sum;
            int right_total = right_sum - right_count * nums[i];
            
            ans.push_back(left_total + right_total);
        }
        
        return ans;
    }
};