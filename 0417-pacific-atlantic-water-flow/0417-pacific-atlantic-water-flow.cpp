// class Solution {
// public:
//     bool dfsP(int r,int c,int prev,vector<vector<int>>&
//     heights,vector<vector<bool>>& visitedP){
//         if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size())
//         return false; if(visitedP[r][c] || heights[r][c] > prev) return
//         false; if(r == 0 || c == 0) return true;

//         visitedP[r][c] = true;
//         return dfsP(r-1,c,heights[r][c],heights,visitedP) ||
//                 dfsP(r,c-1,heights[r][c],heights,visitedP) ||
//                 dfsP(r+1,c,heights[r][c],heights,visitedP) ||
//                 dfsP(r,c+1,heights[r][c],heights,visitedP);
//     }

//     bool dfsA(int r,int c,int prev,vector<vector<int>>&
//     heights,vector<vector<bool>>& visitedA){
//         if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size())
//         return false; if(visitedA[r][c] || heights[r][c] > prev) return
//         false; if(r == heights.size() -1 || c == heights[0].size()-1) return
//         true;

//         visitedA[r][c] = true;
//         return dfsA(r+1,c,heights[r][c],heights,visitedA) ||
//                 dfsA(r,c+1,heights[r][c],heights,visitedA) ||
//                 dfsA(r-1,c,heights[r][c],heights,visitedA) ||
//                 dfsA(r,c-1,heights[r][c],heights,visitedA);
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         vector<vector<int>> res;
//         for(int i = 0;i<heights.size();i++){
//             for(int j = 0; j < heights[0].size();j++){
//                 vector<vector<bool>> visitedP(heights.size(),
//                 vector<bool>(heights[0].size(), false)); vector<vector<bool>>
//                 visitedA(heights.size(), vector<bool>(heights[0].size(),
//                 false));

//                 if(dfsP(i,j,1e8,heights,visitedP) &&
//                 dfsA(i,j,1e8,heights,visitedA)) res.push_back({i,j});
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis) {
        vis[r][c] = true;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) dfs(heights,nr,nc,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; c++) {
            dfs(heights, 0, c, pac);
            dfs(heights, rows - 1, c, atl);
        }
        for (int r = 0; r < rows; r++) {
            dfs(heights, r, 0, pac);
            dfs(heights, r, cols - 1, atl);
        }
        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }
        return ans;
    }
};