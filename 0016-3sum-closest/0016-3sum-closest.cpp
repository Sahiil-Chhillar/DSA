class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiffSum = 0;
        int minDiff = 1e9;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    int currDiff = abs(target - (nums[i]+nums[j]+nums[k]));
                    if(minDiff > currDiff){
                        minDiff = currDiff;
                        minDiffSum = nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return minDiffSum;
    }
}; 