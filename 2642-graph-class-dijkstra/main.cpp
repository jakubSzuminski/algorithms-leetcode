class Graph {
public:
    vector<vector<pair<int, int>>> g;

    // Step 1. - create a Graph adjecency list
    Graph(int n, vector<vector<int>>& edges) {
       g.resize(n);
       // create a graph in a form of adj. list
       for (auto& e: edges) {
           g[e[0]].push_back(make_pair(e[1], e[2]));
       }
    }
    
    // Step 2. - push to the Graph adjecency list
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    // Step 3. - run the dijkstra algorithm for finding
    // the shortest path in a directed weighted graph
    int shortestPath(int node1, int node2) {
        int n = g.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> node_cost(n, INT_MAX);
        node_cost[node1] = 0;
        pq.push({ 0, node1 });

        while (!pq.empty()) {
            int current_cost = pq.top()[0];
            int current_node = pq.top()[1];
            pq.pop();

            if (current_cost > node_cost[current_node]) {
                continue;
            }
            if (current_node == node2) {
                return current_cost;
            }

            for (auto& neighbor : g[current_node]) {
                int neighbor_node = neighbor.first;
                int cost = neighbor.second;
                int new_cost = current_cost + cost;

                if (new_cost < node_cost[neighbor_node]) {
                    node_cost[neighbor_node] = new_cost;
                    pq.push({ new_cost, neighbor_node });
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */