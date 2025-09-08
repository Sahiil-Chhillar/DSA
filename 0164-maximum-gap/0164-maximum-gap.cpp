class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        sort(nums.begin(),nums.end());

        int maxDiff = -1e9, currDiff;
        for(int i = 0; i + 1 < nums.size();i++){
            currDiff = nums[i+1] - nums[i];
            maxDiff = max(maxDiff,currDiff);
        }

        return maxDiff;
    }
};