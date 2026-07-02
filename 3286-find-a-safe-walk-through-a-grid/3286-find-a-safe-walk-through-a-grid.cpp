class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int health, int r, int c,vector<vector<int>>& best) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;

        health -= grid[r][c];

        if (health <= 0) return false;
        if (r == grid.size() - 1 && c == grid[0].size() - 1) return true;
        if (best[r][c] >= health) return false;
        best[r][c] = health;

        bool up = dfs(grid,health,r-1,c,best);
        bool down = dfs(grid,health,r+1,c,best);
        bool left = dfs(grid,health,r,c-1,best);
        bool right = dfs(grid,health,r,c+1,best);

        return up || down || left || right;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> best(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid, health, 0, 0, best);
    }
};