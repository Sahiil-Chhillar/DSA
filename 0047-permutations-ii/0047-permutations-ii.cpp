class Solution {
public:
    void f(int idx ,vector<int>& nums,vector<vector<int>>& result){
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for(int i = idx ; i< nums.size();i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[i],nums[idx]);
            f(idx+1,nums,result);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        f(0,nums,result);
        return result;
    }
};