class Solution {
public:
    int f(int i,int j,string& s, string& t,vector<vector<int>>& dp){
        if(i == s.size()) return t.size()-j;
        if(j == t.size()) return s.size()-i;

        if(dp[i][j] != -1 ) return dp[i][j];

        int m = 1e9,nm = 1e9;
        if(s[i] == t[j]) m = f(i+1,j+1,s,t,dp);
        else {
            // insertion in t
            int case1 = 1 + f(i+1,j,s,t,dp);
            // deletion in t
            int case2 = 1 + f(i,j+1,s,t,dp);
            // replace in t
            int case3 = 1 + f(i+1,j+1,s,t,dp);

            nm = min({case1,case2,case3});
        }

        return dp[i][j] = min(m,nm);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return f(0,0,word1,word2,dp);
    }
};