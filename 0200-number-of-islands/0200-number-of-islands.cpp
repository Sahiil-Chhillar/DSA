class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }

    void bfs(vector<vector<char>>& grid,int r,int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0';

        const vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto& [dx,dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] != '0'){
                    q.push({nx,ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count =0;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == '1'){
                    count++;
                    // dfs(grid,r,c);
                    bfs(grid,r,c);
                }
            }
        }
        return count;
    }
};