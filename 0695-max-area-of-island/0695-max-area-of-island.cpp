class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0 ;c < n;c++){
                int currArea = 0;
                // for one Island
                if(grid[r][c] == 1){
                    queue<pair<int,int>> q;
                    q.push({r,c});
                    grid[r][c] = 0;
                    currArea+=1;

                    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();

                        for(auto& [dx,dy] : dir){
                            int nr = x + dx;
                            int nc = y + dy;

                            if(nr >=0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 1){
                                grid[nr][nc] = 0;
                                q.push({nr,nc});
                                currArea+=1;
                            }
                        }
                    }
                    maxArea = maxArea > currArea ? maxArea : currArea;
                }
            }
        }

        return maxArea;
    }
};