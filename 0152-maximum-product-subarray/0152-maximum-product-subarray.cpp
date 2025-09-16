class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0];
        int n = nums.size();
        int currP = 1;
        for (auto& num : nums){
            currP *= num;
            maxP = max(maxP , currP);
            if(num == 0) currP =1;
        }
        currP = 1;
        for(int i = n-1;i>0;i--){
            currP *= nums[i];
            maxP = max(maxP , currP);
            if(nums[i] == 0) currP =1; 
        }

        return maxP;
    }
};