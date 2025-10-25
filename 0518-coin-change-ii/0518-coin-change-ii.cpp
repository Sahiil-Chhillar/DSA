class Solution {
public:
    int f(int idx,int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(idx == coins.size() || amount < 0) return 0; 

        if(dp[idx][amount] != -1) return dp[idx][amount];
        int t = coins[idx] <= amount ? f(idx,amount - coins[idx],coins,dp) : 0;
        int nt = f(idx +1,amount,coins,dp);

        return dp[idx][amount] = t + nt;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);
    }
};