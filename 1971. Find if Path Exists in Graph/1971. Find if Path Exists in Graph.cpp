class Solution {
public:
    // Parent vector to represent the disjoint set structure
    vector<int> parent;

    // Check if there is a valid path between source and destination
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // Init parent array so that each vertex is its own parent initially
        parent.resize(n);
        for (int j = 0; j < n; ++j) {
            parent[j] = j;
        }

        // Iterate through all edges to perform the union operation
        for (auto& edge : edges) {
            unionSet(find(edge[0]), find(edge[1]));
        }

        // Check if the source and desingation have the same root parent
        return find(source) == find(destination);
    }

    // Helper func to find the root parent of a vertex x
    int find(int x) {
        // Path compression: Recursively makes the parents of the vertices
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Helper func to perform the union operation on two subsets
    void unionSet(int x, int y) {

        // Find the root parents of the vertices
        int rootX = find(x);
        int rootY = find(y);

        // Union by setting the parent of rootX / rootY
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};