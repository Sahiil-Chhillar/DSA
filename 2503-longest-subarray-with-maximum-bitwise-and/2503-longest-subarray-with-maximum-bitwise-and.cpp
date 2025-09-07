class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end()),currLength = 0,maxLength = -1e9;

        for(auto& num : nums){
            if(num == maxi){
                currLength++;
                maxLength = max(maxLength,currLength);
            }
            else currLength = 0;
        }

       return maxLength;
    }
};