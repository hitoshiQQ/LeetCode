class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        // Use a graph to represent the tree
        vector<vector<int>> graph(n);

        // Build the graph from the edges input
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        // This will hold the final result / sizes of the subtrees
        vector<int> res(n);
        vector<int> subtreeSize(n);

        // DFS for calculating init distance and subtree sizes
        function<void(int, int, int)> dfsDistance = [&](int node, int parent, int depth) {
            // Add the depth to the result for the root
            res[0] += depth;

            // Init the size of this subtree
            subtreeSize[node] = 1;

            // Traverse the graph
            for (int& neighbor : graph[node]) {
                if (neighbor != parent) {
                    dfsDistance(neighbor, node, depth + 1);
                    // Update the size of the subtree
                    subtreeSize[node] += subtreeSize[neighbor];
                }
            }
        };

        // DFS calculating result for each node based on the root's result
        function<void(int, int, int)> dfsResult = [&](int node, int parent, int totalDistance) {
            // Set the result for this ndoe
            res[node] = totalDistance;

            // Traverse the graph
            for (int& neighbor : graph[node]) {
                if (neighbor != parent) {
                    // Recalculate the total distance when moving the root from current node to the neighbor
                    int revisedDistance = totalDistance - subtreeSize[neighbor] + n - subtreeSize[neighbor];
                    dfsResult(neighbor, node, revisedDistance);
                }
            }
        };

        // Call the first DFS for the root node to init distance and subtree sizes
        dfsDistance(0, -1, 0);

        // Call the second DFS to calculate the result for each node
        dfsResult(0, -1, res[0]);

        return res;
    }
};