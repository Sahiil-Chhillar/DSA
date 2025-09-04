class Solution {
public:
    void f(int r,int c,int color,vector<vector<int>>& result,int gridColor){
        if(r < 0 || r >= result.size() || c < 0 || c >= result[0].size() || result[r][c] != gridColor) {
            return;
        }

        result[r][c] = color;
        f(r+1,c,color,result,gridColor);
        f(r-1,c,color,result,gridColor);
        f(r,c+1,color,result,gridColor);
        f(r,c-1,color,result,gridColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int gridColor = image[sr][sc];
        if(gridColor == color) return image;
        vector<vector<int>> result = image;
        f(sr,sc,color,result,gridColor);
        return result;
    }
};