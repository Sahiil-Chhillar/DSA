class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        while(k--){
            int prev = -1e9;
            for(int i = 0;i<n;i++){
                for(int j = 0; j<m;j++){
                    if(prev == -1e9) prev = grid[i][j];
                    else{
                        int temp = grid[i][j];
                        grid[i][j] = prev;
                        prev = temp;
                    }
                }
            }
            grid[0][0] = prev;
        }

        return grid;
    }
};