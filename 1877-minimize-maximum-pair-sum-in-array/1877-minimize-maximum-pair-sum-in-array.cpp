class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int maxSum = 0;
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
            maxSum = max(maxSum,nums[l] + nums[r]);
            l++;
            r--;
        }

        return maxSum;
    }
};