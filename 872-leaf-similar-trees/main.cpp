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
    // BEATS 100% OF C++ USERS WHEN IT COMES TO PERFORMANCE

    vector<int> leaf_seq1;
    vector<int> leaf_seq2;

    void dfs(TreeNode* root, int seq) {
        if (root->val && !(root->left) && !(root->right)) {
            if (seq == 1) leaf_seq1.push_back(root->val);
            else if (seq == 2) leaf_seq2.push_back(root->val);
        }

        if (root->left) dfs(root->left, seq);
        if (root->right) dfs(root->right, seq);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, 1);
        dfs(root2, 2);

        if (leaf_seq1.size() != leaf_seq2.size()) {
            return false;
        }

        for (int i = 0; i < leaf_seq1.size(); i++) {
            if (leaf_seq1[i] != leaf_seq2[i]) return false;
        }

        return true;
    }
};