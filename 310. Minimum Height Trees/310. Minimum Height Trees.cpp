class Solution {
public:
    // Func to find the nodes that form trees with the min height
    vector<int> findMinHeightTrees(int num, vector<vector<int>>& edges) {
        // BASE CASE: if there's only one node, it's the root of a minHeightTree
        if (num == 1) {
            return { 0 };
        }

        // Each node will be an index in an adjacency list
        vector<vector<int>> adjacencyList(num);

        // The degree count for each node
        vector<int> degrees(num, 0);

        // Constructor the graph
        for (const auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];

            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
            degrees[nodeA]++;
            degrees[nodeB]++;
        }

        // Init a queue for processing leaf nodes
        queue<int> processingQueue;
        for (int j = 0; j < num; ++j) {
            if (degrees[j] == 1) {
                processingQueue.push(j);
            }
        }

        // Vector to hold the min height tree roots
        vector<int> minHeightRoots;

        // Process the graph
        while (!processingQueue.empty()) {
            // Start a new level
            minHeightRoots.clear();

            // Number of nodes in the current level
            int levelSize = processingQueue.size();

            // Process all nodes in the current level
            for (int j = 0; j < levelSize; ++j) {
                int currentNode = processingQueue.front();
                processingQueue.pop();

                // Add the current node to this level's results
                minHeightRoots.push_back(currentNode);

                // Decrease the degree of adjacent nodes and enqueue new leaf nodes
                for (int adjacentNode : adjacencyList[currentNode]) {
                    // If it becomes a leaf node
                    if (--degrees[adjacentNode] == 1) {
                        processingQueue.push(adjacentNode);
                    }
                }
            }
        }
        return minHeightRoots;
    }
};