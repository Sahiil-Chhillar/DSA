class Solution {
public:
    int f(int i, int j, string& s, string& r,vector<vector<int>>& dp) {
        if (i == s.size() || j == r.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int t = 0;
        if (s[i] == r[j]) t = 1 + f(i + 1, j + 1, s, r,dp);
        int nt = max(f(i, j + 1, s, r,dp), f(i + 1, j, s, r,dp));

        return dp[i][j] = max(t, nt);
    }

    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(s.size()+1,vector<int>(r.size()+1,-1));
        return s.size() - f(0, 0, s, r,dp);
    }
};