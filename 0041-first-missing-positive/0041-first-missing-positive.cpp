class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int missingNum = 1;
        for(auto& num : nums) {
            if(num == missingNum) missingNum++;
            else if (num > missingNum) return missingNum;
        }

        return missingNum;
    }
};