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
    static const int MAX_LEVELS = 10001;
    static const int MIN_VAL = -2147483648;

    int level_score[MAX_LEVELS];
    bool level_visited[MAX_LEVELS];

    void dfs(TreeNode* node, int level) {
        level_visited[level] = true;
        level_score[level] = max(level_score[level], node->val);

        if (node->left) {
            dfs(node->left, level + 1);
        }

        if (node->right) {
            dfs(node->right, level + 1);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        for (int i = 0; i < MAX_LEVELS; i++) {
            level_score[i] = MIN_VAL;
            level_visited[i] = false;
        }

        if (root != NULL) {
            dfs(root, 1);
        }

        vector<int> result;
        for (int i = 1; i < MAX_LEVELS; i++) {
            if (!level_visited[i]) break;
            result.push_back(level_score[i]);
        }

        return result;
    }
};