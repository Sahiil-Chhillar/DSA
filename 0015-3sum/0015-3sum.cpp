class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++){
            int target = -nums[i];
            int st = i+1;
            int end = nums.size()-1;
            while(st < end){
                int sum = nums[st] + nums[end];
                if(sum == target){
                    result.insert({nums[i],nums[st],nums[end]});
                    st++;end--;
                } 
                else if(sum < target) st++;
                else end--;
            }
        }
        return vector<vector<int>>(result.begin(),result.end());
    }
};