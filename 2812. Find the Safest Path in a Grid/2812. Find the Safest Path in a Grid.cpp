class UnionFinder {
public:
    // Variables 
    vector<int> parent;
    int count;

    // Constructor init UnionFinder with 'n' elements
    UnionFinder(int n) : count(n), parent(n) {
        // Fill the parent vector with indices of itself
        iota(parent.begin(), parent.end(), 0);
    }

    // Unite 2 groups, if they are already united, ret false
    bool unite(int a, int b) {
        int root_A = find(a);
        int root_B = find(b);

        // Assign the parent of 'A' root to be 'B' root
        if (root_A == root_B) {
            return false;
        }

        parent[root_A] = root_B;
        --count;
        return true;
    }

    //Find the root of the group that element'x' is in
    int find(int x) {
        // Path compression: point this node directly to the root
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
public:
    // Calculate the max safeness factor of a given grid
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int gridSize = grid.size();

        // If the start or end points are blocked, ret zero
        if (grid[0][0] || grid[gridSize - 1][gridSize - 1]) {
            return 0;
        }

        // Queue for BFS
        queue<pair<int, int>> queue;

        // Init distance array with large values
        int distance[gridSize][gridSize];
        memset(distance, 0x3f, sizeof(distance));

        // Calc distances from each hazard in the grid
        for (int j = 0; j < gridSize; ++j) {
            for (int i = 0; i < gridSize; ++i) {
                // Hazards have zero distance
                if (grid[j][i]) {
                    distance[j][i] = 0;

                    // Add hazards to the queue
                    queue.emplace(j, i);
                }
            }
        }

        // Directions for neighbors
        int directions[5] = { -1, 0, 1, 0, -1 };

        // Perform bfs to calculate the distance of each cell from the closest hazard
        while (!queue.empty()) {
            auto [j, i] = queue.front();
            queue.pop();
            for (int q = 0; q < 4; ++q) {
                int x = j + directions[q];
                int y = i + directions[q + 1];
                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && distance[x][y] == 0x3f3f3f3f) {
                    // Update distance
                    distance[x][y] = distance[j][i] + 1;
                    // Enqueue the current cell
                    queue.emplace(x, y);
                }

            }
        }

        // Sort the cells by distance in descending order
        vector<tuple<int, int, int>> distances;
        for (int j = 0; j < gridSize; ++j) {
            for (int i = 0; i < gridSize; ++i) {
                distances.emplace_back(distance[j][i], j, i);
            }
        }
        sort(distances.begin(), distances.end(), greater<>());

        // UnionFinder to keep track of connectivity
        UnionFinder uf(gridSize * gridSize);

        // Try to unite cells, starting from the highest distance from hazards
        for (auto [_distance, j, i] : distances) {
            for (int q = 0; q < 4; ++q) {
                int x = j + directions[q];
                int y = i + directions[q + 1];

                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && distance[x][y] >= _distance) {
                    uf.unite(j * gridSize + i, x * gridSize + y);
                }
            }

            // If the start and end pointers are connected, ret the current distance
            if (uf.find(0) == uf.find(gridSize * gridSize - 1)) {
                return _distance;
            }
        }
        return 0;
    }
};