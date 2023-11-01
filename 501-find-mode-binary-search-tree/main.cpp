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
    // simple DFS-based approach
    // with map<int, int> tracking the count
    // of each value in a tree

    int max_count = 0;
    map<int, int> count;
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (count.find(root->val) != count.end()) {
            count[root->val]++;
        } else {
            count[root->val] = 1;
        }

        if (count[root->val] > max_count) {
            max_count = count[root->val];
            ans.clear();
            ans.push_back(root->val);
        } else if (count[root->val] == max_count) {
            ans.push_back(root->val);
        }

        if (root->left) {
            dfs(root->left);
        }

        if (root->right) {
            dfs(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        if (root != NULL) {
            dfs(root);
        }

        return ans;
    }
};