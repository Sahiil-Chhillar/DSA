class Solution {
public:
    bool f(int move,int r,int c,vector<vector<int>>& grid){
        int n = grid.size();
        if(move > n * n -1) return false;
        if(grid[r][c] != move) return false;
        if(grid[r][c] == n*n-1) return true;

        bool c1 = false;
        if(r+1 < n && c -2 >= 0) c1 = f(move+1,r+1,c-2,grid);

        bool c2 = false;
        if(r+2 < n && c -1 >= 0) c2 = f(move+1,r+2,c-1,grid);

        bool c3 = false;
        if(r+2 < n && c +1 < n) c3 = f(move+1,r+2,c+1,grid);

        bool c4 = false;
        if(r+1 < n && c + 2 < n) c4 = f(move+1,r+1,c+2,grid);

        bool c5 = false;
        if(r-1 >= 0 && c - 2 >=0) c5 = f(move+1, r-1,c-2,grid);

        bool c6 = false;
        if(r-2 >=0 && c - 1 >=0) c6 = f(move+1,r-2,c-1,grid);

        bool c7 = false;
        if(r-2 >=0 && c + 1 < n) c7 = f(move+1,r-2,c+1,grid);
 
        bool c8 = false;
        if(r-1 >= 0 && c+2 < n) c8 = f(move+1,r-1,c+2,grid);

        return c1||c2||c3||c4||c5||c6||c7||c8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return f(0,0,0,grid);
    }
};