class Solution {
public:
    // 1. Construct a graph adjecency list
    // 2. Run a simple BFS
    // 3. Return the maximum achieved distance from the start node

    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        construct_graph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutes = -1;

        while (!q.empty()) {
            ++minutes;
            for (int level_size = q.size(); level_size > 0; --level_size) {
                int current_node = q.front();
                q.pop();
                visited.insert(current_node);
                for (int adjacent_node : graph[current_node]) {
                    if (!visited.count(adjacent_node)) {
                        q.push(adjacent_node);
                    }
                }
            }
        }

        return minutes;
    }

    void construct_graph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        construct_graph(root->left);
        construct_graph(root->right);
    }
};