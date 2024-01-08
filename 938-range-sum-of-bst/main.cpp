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
    int l;
    int h;
    int ans = 0;

    void dfs(TreeNode* root) {
        if (root->val) {
            if (root->val >= l && root->val <= h) {
                ans += root->val;
            }
        }

        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;

        if (root) {
            dfs(root);
        }

        return ans;
    }
};