class Solution {
public:
    int f (int r, int c, vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(r >= mat.size() || c < 0 || c >= mat[0].size()) return 1e9;
        if(r == mat.size()-1) return mat[r][c];

        if(dp[r][c] != 1e9) return dp[r][c];
        return dp[r][c] = mat[r][c] + min({f(r+1,c-1,mat,dp),f(r+1,c,mat,dp),f(r+1,c+1,mat,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = 1e9;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),1e9));
        for(int c = 0 ; c < matrix[0].size();c++){
            int currMin = f(0,c,matrix,dp);
            minSum = currMin < minSum ? currMin : minSum;
        }
        return minSum;
    }
};