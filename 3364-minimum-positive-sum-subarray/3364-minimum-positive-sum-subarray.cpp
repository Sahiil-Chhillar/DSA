class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prefix[101];
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];

        int best = 100001;
        for (int length = l; length <= r; ++length) {
            for (int start = 0; start + length <= n; ++start) {
                int sum = prefix[start + length] - prefix[start];
                if (sum == 1) return 1;
                if (sum > 0 && sum < best) best = sum;
            }
        }

        return best == 100001 ? -1 : best;
    }
};