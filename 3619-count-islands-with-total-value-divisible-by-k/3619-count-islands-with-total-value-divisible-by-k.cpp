class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int count = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) continue;

                long long sum = 0;
                sum += grid[i][j];
                grid[i][j] = 0;
                st.push({i, j});
                
                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                            sum += grid[nx][ny];
                            grid[nx][ny] = 0;
                            st.push({nx, ny});
                        }
                    }
                }

                if (sum % k == 0) count++;
            }
        }

        return count;
    }
};