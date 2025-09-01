class Solution {
public:
    int f(int idx ,vector<int>& nums, int target,vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(target < 0 || idx == nums.size()) return 0;

        if(dp[idx][target] != -1) return dp[idx][target];

        int take = f(0,nums,target-nums[idx],dp);
        int notTake = f(idx+1,nums,target,dp);

        return dp[idx][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return f(0,nums,target,dp);
    }
};