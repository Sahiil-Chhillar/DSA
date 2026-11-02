class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int medianElement = nums[nums.size()/2];

        int minMoves = 0;
        for(auto& num : nums){
            minMoves += abs(num - medianElement);
        }

        return minMoves;
    }
};