class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const int n = nums.size();
        int best = -1;

        for (int start = 0; start < n; ++start) {
            int sum = 0;
            int endLimit = start + r;
            if (endLimit > n) endLimit = n;

            for (int end = start; end < endLimit; ++end) {
                sum += nums[end];
                int length = end - start + 1;
                if (length < l || sum <= 0) continue;
                if (sum == 1) return 1;
                if (best == -1 || sum < best) best = sum;
            }
        }

        return best;
    }
};