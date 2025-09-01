class Solution {
public:
    int f(int idx,vector<int>& days, vector<int>& costs,vector<int>& dp){
        if(idx == days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int case1 = costs[0] + f(idx+1,days,costs,dp);
        int j = idx;
        while (j < days.size() && days[j] < days[idx] + 7) j++;// check j out of bounds
        int case2 = costs[1] + f(j,days,costs,dp);
        int k = idx;
        while (k < days.size() && days[k] < days[idx] + 30) k++;
        int case3 = costs[2] + f(k,days,costs,dp);

        return dp[idx] = min({case1,case2,case3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return f(0,days,costs,dp);
    }
};