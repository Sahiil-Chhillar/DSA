class Solution {
public:
    int f(int i,vector<int>& nums,int prevIdx,vector<vector<int>>& dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        int p = 0;
        if( prevIdx == -1 ||nums[prevIdx] < nums[i]){
            int case1 = 1 + f(i+1,nums,i,dp);
            int case2 = f(i+1,nums,prevIdx,dp);
            p = max(case1,case2);
        } 
        int np = f(i+1,nums,prevIdx,dp);

        return dp[i][prevIdx+1] = max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(0,nums,-1,dp);
    }
};