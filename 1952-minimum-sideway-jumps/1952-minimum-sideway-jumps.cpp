class Solution {
public:
    int f(int idx, int lane, vector<int>& obs,vector<vector<int>>& dp) {
        if (idx >= obs.size() - 1) return 0;


        if(dp[idx][lane] !=-1) return dp[idx][lane];


        int ans = INT_MAX;
        if(obs[idx + 1] != lane) {
            ans = f(idx+1,lane,obs,dp);
        }
        else{
            if(lane == 1){
                int case1 = (obs[idx] != 2) ? 1 + f(idx,2,obs,dp) : INT_MAX;
                int case2 = (obs[idx] != 3) ? 1 + f(idx,3,obs,dp) : INT_MAX;
                ans = min(case1,case2);
            }
            else if(lane == 2){
                int case1 = (obs[idx] != 1) ? 1 + f(idx,1,obs,dp) : INT_MAX;
                int case2 = (obs[idx] != 3) ? 1 + f(idx,3,obs,dp) : INT_MAX;
                ans = min(case1,case2);
            }
            else {
                int case1 = (obs[idx] != 1) ? 1 + f(idx,1,obs,dp) : INT_MAX;
                int case2 = (obs[idx] != 2) ? 1 + f(idx,2,obs,dp) : INT_MAX;
                ans = min(case1,case2);
            }
        }
        return dp[idx][lane] = ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size()+1,vector<int>(4,-1));
        return f(0, 2, obstacles,dp);
    }
};