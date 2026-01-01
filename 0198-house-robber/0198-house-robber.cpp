class Solution {
public:
    int f(int idx, vector<int>& nums,vector<int>& dp) {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(nums[idx] + f(idx+2,nums,dp),f(idx+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // vector<int> dp(n, -1);
        // return f(0, nums,dp);

        // tabulation
        // dp[0] = nums[0];
        // dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        // for(int i = 2 ; i < n ; i++){
        //     dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        // }

        // return dp[n-1];

        // space optimastion 
        int secLast = nums[0];
        int last = nums[1] > nums[0] ? nums[1] : nums[0];
        for(int i = 2;i < n;i++){
            int currMax = max(secLast + nums[i] ,last);
            secLast = last;
            last = currMax;
        }
        return last;
    }
};