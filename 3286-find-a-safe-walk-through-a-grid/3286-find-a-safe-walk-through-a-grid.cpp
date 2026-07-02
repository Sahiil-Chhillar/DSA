// class Solution {
// public:
//     bool dfs(vector<vector<int>>& grid, int health, int r, int c,vector<vector<int>>& best) {
//         if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;

//         health -= grid[r][c];

//         if (health <= 0) return false;
//         if (r == grid.size() - 1 && c == grid[0].size() - 1) return true;
//         if (best[r][c] >= health) return false;
//         best[r][c] = health;

//         bool up = dfs(grid,health,r-1,c,best);
//         bool down = dfs(grid,health,r+1,c,best);
//         bool left = dfs(grid,health,r,c-1,best);
//         bool right = dfs(grid,health,r,c+1,best);

//         return up || down || left || right;
//     }

//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         vector<vector<int>> best(grid.size(),vector<int>(grid[0].size(),-1));
//         return dfs(grid, health, 0, 0, best);
//     }
// };
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        best[0][0] = startHealth;

        priority_queue<vector<int>> pq;
        pq.push({startHealth, 0, 0});

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currHealth = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == m - 1 && c == n - 1) return true;
            if (currHealth < best[r][c]) continue;

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int nextHealth = currHealth - grid[nr][nc];
                if (nextHealth > 0 && nextHealth > best[nr][nc]) {
                    best[nr][nc] = nextHealth;
                    pq.push({nextHealth, nr, nc});
                }
            }
        }

        return false;
    }
};