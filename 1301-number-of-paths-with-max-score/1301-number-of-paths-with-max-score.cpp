class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {1, 1}};

        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (board[r][c] == 'X' || board[r][c] == 'S')continue;

                int best = -1;
                long long count = 0;

                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= n || nc >= n || score[nr][nc] == -1) continue;

                    if (score[nr][nc] > best) {
                        best = score[nr][nc];
                        count = ways[nr][nc];
                    }
                    else if (score[nr][nc] == best) {
                        count = (count + ways[nr][nc]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                score[r][c] = best;
                ways[r][c] = count % MOD;

                if (board[r][c] != 'E') score[r][c] += board[r][c] - '0';
            }
        }

        if (score[0][0] == -1) return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};