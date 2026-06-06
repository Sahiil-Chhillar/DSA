class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for(auto& num : nums) totalSum += num;

        int lsum = 0;
        vector<int> res;
        for(auto& num : nums){
            totalSum = totalSum - num;
            res.push_back(abs(lsum-totalSum));
            lsum += num;
        }
        return res;
    }
};