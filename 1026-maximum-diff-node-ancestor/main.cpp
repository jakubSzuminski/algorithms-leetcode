/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int max_val, int min_val) {
        int new_max_val = max(max_val, root->val);
        int new_min_val = min(min_val, root->val);

        if (root->left) dfs(root->left, new_max_val, new_min_val);
        if (root->right) dfs(root->right, new_max_val, new_min_val);

        if (!(root->left) && !(root->right)) {
            ans = max(ans, abs(new_max_val - new_min_val));
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, -1, INT_MAX);
        return ans;
    }
};