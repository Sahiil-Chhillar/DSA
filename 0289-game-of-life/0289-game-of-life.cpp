class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dir = {{-1,0}, {-1,1}, {0,1}, {1,1},{1,0}, {1,-1}, {0,-1}, {-1,-1}};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int cnt = 0;
                for (auto& [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && (board[nr][nc] == 1 || board[nr][nc] == 2)) cnt++;
                }

                
                if (board[r][c] == 1 && (cnt < 2 || cnt > 3)) board[r][c] = 2; // Alive -> Dead
                else if (board[r][c] == 0 && cnt == 3) board[r][c] = 3; // Dead -> Alive
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 2) board[r][c] = 0;
                else if (board[r][c] == 3) board[r][c] = 1;
            }
        }
    }
};