class Solution {
public:
    int f(int r,int c,vector<vector<char>>& matrix,vector<vector<int>>& dp,int & maxSide){
        if(r >= matrix.size() || c >= matrix[0].size()) return 0;

        if(dp[r][c] != -1) return dp[r][c];
        
        int c1 = 1 + f(r,c+1,matrix,dp,maxSide);
        int c2 = 1 + f(r+1,c+1,matrix,dp,maxSide);
        int c3 = 1 + f(r+1,c,matrix,dp,maxSide);

        if(matrix[r][c] != '0'){
            int side = min({c1,c2,c3});
            maxSide = max(maxSide , side);
            return dp[r][c] = side;
        }
        else return dp[r][c] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int maxSide = 0;
        f(0,0,matrix,dp,maxSide);
        return maxSide * maxSide;
    }
};