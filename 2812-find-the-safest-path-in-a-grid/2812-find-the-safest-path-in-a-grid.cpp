class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // dist nikal le har theif se har empty cell ki
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // ab dijkstar lga de high safe score k liye
        priority_queue<vector<int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (x == n - 1 && y == n - 1) return safe;
            if (safe < best[x][y]) continue;

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int newSafe = min(safe, dist[nx][ny]);
                    if (newSafe > best[nx][ny]) {
                        best[nx][ny] = newSafe;
                        pq.push({newSafe, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};