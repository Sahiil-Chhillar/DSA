class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: up, down, left, right.
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int count = 0;

        // Stack stores the coordinates of cells to process.
        stack<pair<int, int>> st;

        // Traverse every cell in the grid.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip water and already visited cells.
                if (grid[i][j] == 0) {
                    continue;
                }

                // A new island has been discovered.
                long long sum = 0;

                // Mark the starting cell visited before pushing.
                sum += grid[i][j];
                grid[i][j] = 0;
                st.push({i, j});

                // Explore the entire island iteratively.
                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    // Explore all four neighboring cells.
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        // Check whether the neighbor is inside the grid.
                        if (nx >= 0 && nx < m &&
                            ny >= 0 && ny < n &&
                            grid[nx][ny] > 0) {

                            // Include its value in the island sum.
                            sum += grid[nx][ny];

                            // Mark visited before pushing to avoid duplicates.
                            grid[nx][ny] = 0;

                            // Process this neighbor later.
                            st.push({nx, ny});
                        }
                    }
                }

                // Count the island if its sum is divisible by k.
                if (sum % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};