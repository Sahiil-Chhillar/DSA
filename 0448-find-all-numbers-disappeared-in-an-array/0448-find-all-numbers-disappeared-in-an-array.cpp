class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPresent(n+1,false);

        for(auto& num : nums) isPresent[num] = true;
        vector<int> ans;
        for(int i = 1 ; i <= n ; i++){
            if(!isPresent[i]) ans.push_back(i);
        }

        return ans;
    }
};