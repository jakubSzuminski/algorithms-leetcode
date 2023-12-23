class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;

        int x = 0;
        int y = 0;
        visited.insert(make_pair(x, y));

        for (int i = 0; i < path.size(); i++) {
            switch(path[i]) {
                case 'N':
                    y += 1;
                    break;
                case 'S':
                    y -= 1;
                    break;
                case 'E':
                    x += 1;
                    break;
                case 'W':
                    x -= 1;
                    break;
            }

            pair<int, int> pos = make_pair(x, y);
            auto it = find(visited.begin(), visited.end(), pos); 

            if (it != visited.end())
                return true;
            else
                visited.insert(pos);
        }

        return false;
    }
};