class Solution {
public:
    void f(int idx ,vector<int>& nums,int k, int n, vector<vector<int>>& result,vector<int>& currComb){
        if(currComb.size() > k) return;
        if(currComb.size() == k && n == 0){
            result.push_back(currComb);
            return;
        }
        if(idx == nums.size()) return;
        currComb.push_back(nums[idx]);
        f(idx+1,nums,k,n-nums[idx],result,currComb);
        currComb.pop_back();
        f(idx+1,nums,k,n,result,currComb);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i  = 1 ; i<= 9 ;i++) nums.push_back(i);

        vector<vector<int>> result;
        vector<int> currComb;
        f(0,nums,k,n,result,currComb);
        return result;
    }
};