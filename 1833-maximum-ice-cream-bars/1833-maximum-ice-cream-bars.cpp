// class Solution {
// public:
//     int f(vector<int>& costs, int coins, int idx,vector<vector<int>>& dp){
//         if(idx >= costs.size()) return 0;

//         if(dp[idx][coins] != -1) return dp[idx][coins];

//         int p = (costs[idx] <= coins) ? 1 + f(costs,coins-costs[idx],idx+1,dp) : 0;
//         int np = f(costs,coins,idx+1,dp);

//         return dp[idx][coins] =  p > np ? p : np;
//     }
//     int maxIceCream(vector<int>& costs, int coins) {
//         vector<vector<int>> dp(costs.size(),vector<int>(coins+1,-1));
//         return f(costs,coins,0,dp);
//     }
// };


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (auto& cost : costs) {
            if (cost > coins) break;
            coins -= cost;
            cnt++;
        }
        return cnt;
    }
};