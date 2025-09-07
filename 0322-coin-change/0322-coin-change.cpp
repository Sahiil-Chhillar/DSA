class Solution {
public:
    int f(int i, vector<int>& curr,int target,vector<vector<int>>& dp){
        if(target <= 0) return 0;
        if(i == curr.size()) return 1e9;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int t = (curr[i] <= target) ? t = 1 + f(i,curr,target - curr[i],dp) : 1e9;
        int nt = f(i+1,curr,target,dp);
        return dp[i][target] = min(t,nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1 , vector<int>(amount+1,-1));
        int res = f(0,coins,amount,dp);
        return res == 1e9 ? -1: res;
    }
};