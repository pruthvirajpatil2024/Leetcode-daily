// Disjoint Set Union (DSU) class definition
class DisjointSet {
public:
    vector<int> parent; // Stores the parent of each node
    vector<int> area;   // Stores the size of each connected component

    // Constructor to initialize DSU with `n` elements
    DisjointSet(int n) {
        parent.resize(n);
        area.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Each node is its own parent initially
            area[i] = 1;    // Initial size of each component is 1
        }
    }

    // Function to find the parent of a node with path compression
    int findParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }


    // Function to union two sets based on size
    void unionSet(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV) return; // Already in the same set

        // Union by size
        if (area[rootU] < area[rootV]) {
            parent[rootU] = rootV;
            area[rootV] += area[rootU];
        } else {
            parent[rootV] = rootU;
            area[rootU] += area[rootV];
        }
    }
};

// Solution class to solve the problem
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize DSU for the entire grid
        DisjointSet ds(rows * cols);

        // Direction vectors for traversing up, down, left, and right
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Step 1: Union adjacent `1`s in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int u = (cols*i) + j; // Flatten 2D index to 1D

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        // Check bounds and ensure the neighbor is also `1`
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                            int v = cols * ni + nj;
                            ds.unionSet(u, v);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        long long result = INT_MIN;
        bool hasZero = false; // Flag to check if there are any zeros in the grid
        set<int> unique_Parents; // To store unique parents for a `0`'s neighbors

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    long long ans=0; // Start with the flipped `0`

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        // Check bounds and ensure the neighbor is `1`
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                            int neighbor = cols * ni + nj;
                            int parent = ds.findParent(neighbor);
                            unique_Parents.insert(parent);
                        }
                    }

                    // Sum up the sizes of unique neighboring components
                    for (int parent : unique_Parents) {
                        ans += ds.area[parent];
                    }
                    unique_Parents.clear(); // Clear the set for the next `0`

                    // Update the result with the largest island size found
                    result = max(result, ans+1);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        if (!hasZero) return rows * cols;

        return result;
    }
};
