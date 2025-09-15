class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int st = i+1;
            int end = nums.size()-1;
            while(st < end){
                int sum = nums[st] + nums[end];
                if(sum == target){
                    result.push_back({nums[i],nums[st],nums[end]});
                    while(st < end && nums[st] == nums[st+1]) st++;
                    while(st < end && nums[end] == nums[end-1]) end--;
                    st++;end--;
                } 
                else if(sum < target) st++;
                else end--;
            }
        }
        return result;
    }
};