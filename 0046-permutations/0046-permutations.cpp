class Solution {
public:
    void f(int idx ,vector<int>& nums,vector<vector<int>>& result){
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = idx ; i< nums.size();i++){
            swap(nums[i],nums[idx]);
            f(idx+1,nums,result);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        f(0,nums,result);
        return result;
    }
};