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

/*
    This solution beats 100% of users when it comes to runtime.

    It's based on a simple DFS algorithm from which we get (count, sum) pair
    of the subtree where count = number of nodes in the subtree, sum = sum of
    values of the nodes from the subtree.

    Based on that, we calculate the average value of the subtree and update the answer.
*/

class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        int count = 0;
        int sum = 0;

        if (root->left) {
            pair<int, int> left_subtree = dfs(root->left);
            count += left_subtree.first;
            sum += left_subtree.second;
        }

        if (root->right) {
            pair<int, int> right_subtree = dfs(root->right);
            count += right_subtree.first;
            sum += right_subtree.second;
        }

        count += 1;
        sum += root->val;

        if ((sum / count) == root->val) {
            ans++;
        }

        pair<int, int> result;
        result.first = count;
        result.second = sum;
        return result;
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};