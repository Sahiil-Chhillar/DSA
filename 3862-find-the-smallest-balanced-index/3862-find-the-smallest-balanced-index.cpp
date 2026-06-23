class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long leftSum = 0;
        for(auto& num : nums) leftSum += num;

        long long rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            leftSum -= nums[i];
            if(leftSum == rightProduct) return i;
            
            // check Overflow before multiplying 
            if(rightProduct > leftSum/nums[i]) break;
            rightProduct *= nums[i];
        }
        return -1;
    }
};