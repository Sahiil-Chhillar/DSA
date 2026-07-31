// class Solution {
// public:
//     int f(int idx , vector<int>&nums,int k,vector<vector<int>>& dp){
//         if(k == 0) return 0;
//         if(idx >= nums.size()) return 1e9 + 1;

//         if(dp[idx][k] != -1) return dp[idx][k];

//         int robbed = max(nums[idx], f(idx+2,nums,k-1,dp)); // capacity
//         int notRobbed = f(idx+1,nums,k,dp);

//         return dp[idx][k] = min(robbed,notRobbed);
//     }
//     int minCapability(vector<int>& nums, int k) {
//         vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
//         return f(0,nums,k,dp);
//     }
// };


// minimum capability of the robber to steal at least k houses (similar to koko question !!)
// Think of binary search on answers !!

class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k) {
        int idx=0;
        while (idx<nums.size()) {
            if (nums[idx] <= mid) {
                idx +=2;
                k--;
            }
            else idx++;

            if (k==0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int st = 1; 
        int end = *max_element(nums.begin(), nums.end());
        
        while (st < end) {
            int mid = st + (end - st)/2;
            if (isPossible(mid, nums, k)) end = mid;
            else st = mid+1;
        }
        return end;
    }
};