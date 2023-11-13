class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // step 0 - take care of the edge case
        if (source == target) {
            return 0;
        }

        // step 1 - create a graph
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                g[routes[i][j]].push_back(i);
            }
        }

        // step 2 - create a queue and fill it
        queue<int> q;
        vector<bool> visited(100002, false);
        for (int i = 0; i < g[source].size(); i++){
            q.push(g[source][i]);
        }

        // step 3 - run BFS
        int bus_count = 1;
        while (q.size()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.front(); q.pop();

                // Iterate over the stops in the current route.
                for (auto stop: routes[route]) {
                    if (stop == target) {
                        return bus_count;
                    }

                    // Iterate over the next possible routes from the current stop.
                    for (auto next_route : g[stop]) {
                        if (!visited[next_route]) {
                            visited[next_route] = true;
                            q.push(next_route);
                        }
                    }
                }
            }

            bus_count++;
        }

        return -1;
    }
};