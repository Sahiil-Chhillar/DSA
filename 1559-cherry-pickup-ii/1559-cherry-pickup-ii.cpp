class Solution {
public:
    int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(r >= grid.size() || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int val = grid[r][c1];
        if(c1 != c2) val += grid[r][c2];

        // int case1 = val + f(r+1,c1-1,c2-1,grid,dp);
        // int case2 = val + f(r+1,c1-1,c2,grid,dp);
        // int case3 = val + f(r+1,c1-1,c2+1,grid,dp);
        // int case4 = val + f(r+1,c1,c2-1,grid,dp);
        // int case5 = val + f(r+1,c1,c2,grid,dp);
        // int case6 = val + f(r+1,c1,c2+1,grid,dp);
        // int case7 = val + f(r+1,c1+1,c2-1,grid,dp);
        // int case8 = val + f(r+1,c1+1,c2,grid,dp);
        // int case9 = val + f(r+1,c1+1,c2+1,grid,dp);

        int maxi = -1e9;
        for(int i = -1 ; i<=1 ; i++){
            for(int j = -1; j <= 1 ; j++){
                maxi = max(maxi , val + f(r + 1,c1 - i , c2 - j , grid ,dp));
            }
        }
        
        return dp[r][c1][c2] =  maxi;
        // return dp[r][c1][c2] = max({case1,case2,case3,case4,case5,case6,case7,case8,case9});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(0,0,grid[0].size()-1,grid,dp);
    }
};