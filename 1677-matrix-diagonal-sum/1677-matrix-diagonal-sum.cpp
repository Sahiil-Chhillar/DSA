class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int pSum = 0;
        for(int i = 0,j = m-1 ; i< m && j >=0 ; i++ , j--){
            pSum += mat[i][i];
            pSum += mat[i][j];
        }
        if(m%2 != 0) pSum -= mat[m/2][m/2];
        return pSum;
    }
};