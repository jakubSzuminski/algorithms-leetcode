class Solution {
public:
    const int shift = 100001;
    vector<int> g[200005]; // graph, a list of neighbors
    bool visited[200005];
    vector<int> result;

    void dfs(int node) {
        if (visited[node]) {
            return;
        }

        result.push_back(node - shift);
        visited[node] = true;

        for (int i = 0; i < g[node].size(); i++) {
            dfs(g[node][i]);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& p) {
        // 0. create variables and reset the arrays
        int n = p.size();
        result.clear();

        for (int i = 0; i < 200005; i++) {
            visited[i] = false;
        }

        // 1. create a graph
        for (int i = 0; i < n; i++) {
            g[p[i][0] + shift].push_back(p[i][1] + shift);
            g[p[i][1] + shift].push_back(p[i][0] + shift);
        }

        // 2. find the first element (which has only one neighbor)
        int first;
        for (int i = 0; i < n; i++) {
            if (g[p[i][0] + shift].size() == 1) {
                first = p[i][0] + shift;
            }

            if (g[p[i][1] + shift].size() == 1) {
                first = p[i][1] + shift;
            }
        }

        // 3. run the dfs from the first element
        dfs(first);

        return result;
    }
};