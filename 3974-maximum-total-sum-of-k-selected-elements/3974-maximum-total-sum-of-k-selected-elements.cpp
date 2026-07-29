class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());

        long long sum = 0;
        int i = 0;
        while(k--){
            if(mul) sum += 1LL * nums[i++] * mul--;
            else sum += nums[i++];
        }

        return sum;
    }
};