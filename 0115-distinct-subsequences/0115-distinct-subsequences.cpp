class Solution {
public:
    int f(int i , int j,string& s, string& t,vector<vector<int>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int matched = 0;
        if(s[i] == t[j]) matched = f(i+1,j+1,s,t,dp);
        int notMatched = f(i+1,j,s,t,dp);
        return dp[i][j] = matched + notMatched;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        return f(0,0,s,t,dp);
    }
};