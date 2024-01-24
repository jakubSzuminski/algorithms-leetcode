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

    void dfs(TreeNode* root, int occurences[]) {
        int o[10];
        for (int i = 0; i <= 9; i++)
            o[i] = occurences[i];
        // copy the occurences array by value
        // as it has only 10 elements

        o[root->val]++;

        if (root->left || root->right) {
            if (root->left) dfs(root->left, o);
            if (root->right) dfs(root->right, o);
        } else {
            bool odd = false;
            bool palindrome = true;

            for (int i = 1; i <= 9; i++) {
                if (o[i] % 2 == 1) {
                    if (odd) {
                        palindrome = false;
                        break;
                    } else {
                        odd = true;
                    }
                }
            }

            if (palindrome) ans++;
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int occurences[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        dfs(root, occurences);
        return ans;
    }
};