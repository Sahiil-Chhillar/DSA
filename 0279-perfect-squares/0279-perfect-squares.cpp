class Solution {
public:
    int f(int idx,vector<int>& sq, int target,vector<vector<int>>& dp){
        if(target == 0) return 0;
        if(target < 0 || idx == sq.size()) return 1e9;

        if(dp[idx][target] != -1) return dp[idx][target];

        int p = 1 + f(idx,sq,target - sq[idx],dp);
        int np = f(idx+1,sq,target,dp);

        return dp[idx][target] = min (p,np);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i = 1; i * i <= n ;i++){
            sq.push_back(i*i);
        }
        vector<vector<int>> dp(sq.size()+1,vector<int>(n + 1,-1));
        return f(0,sq,n,dp);
    }
};