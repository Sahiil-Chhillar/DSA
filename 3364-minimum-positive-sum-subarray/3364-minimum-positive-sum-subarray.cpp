class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int best = -1;

        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int end = start; end < n && end - start + 1 <= r; ++end) {
                sum += nums[end];
                int length = end - start + 1;
                if (length >= l && sum > 0 && (best == -1 || sum < best)) {
                    best = sum;
                }
            }
        }

        return best;
    }
};