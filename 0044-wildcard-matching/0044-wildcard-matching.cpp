class Solution {
public:
    bool f(int i,int j,string& s, string& p,vector<vector<int>>& dp){
        if(i == s.size() && j == p.size()) return true;
        if(j == p.size()) return false;
        if(i == s.size()){
            while(j != p.size()){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j]) {
            return dp[i][j] = f(i+1,j+1,s,p,dp);
        }
        else{
            if(p[j] == '?') return dp[i][j] = f(i+1,j+1,s,p,dp);
            else if(p[j] == '*'){
                return dp[i][j] = f(i+1,j,s,p,dp) || f(i,j+1,s,p,dp);
            }
            else return dp[i][j] = false;
        }

        return dp[i][j] = true;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(0,0,s,p,dp);
    }
};