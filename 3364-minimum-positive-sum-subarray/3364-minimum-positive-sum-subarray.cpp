class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prefix[101], coords[101], rank[101], freq[101] = {};
        prefix[0] = coords[0] = 0;
        for (int i = 1; i <= n; ++i) prefix[i] = coords[i] = prefix[i - 1] + nums[i - 1];

        sort(coords, coords + n + 1);
        int count = unique(coords, coords + n + 1) - coords;
        for (int i = 0; i <= n; ++i)
            rank[i] = lower_bound(coords, coords + count, prefix[i]) - coords;

        unsigned long long active[2] = {};
        int best = 100001;
        for (int end = 1; end <= n; ++end) {
            int add = end - l;
            if (add >= 0) {
                int k = rank[add];
                if (++freq[k] == 1) active[k >> 6] |= 1ULL << (k & 63);
            }
            int remove = end - r - 1;
            if (remove >= 0) {
                int k = rank[remove];
                if (--freq[k] == 0) active[k >> 6] &= ~(1ULL << (k & 63));
            }

            int k = rank[end], word = k >> 6, bit = k & 63;
            unsigned long long candidates = bit ? active[word] & ((1ULL << bit) - 1) : 0;
            int previous = -1;
            if (candidates) previous = word * 64 + 63 - __builtin_clzll(candidates);
            else if (word > 0 && active[word - 1])
                previous = (word - 1) * 64 + 63 - __builtin_clzll(active[word - 1]);

            if (previous >= 0) {
                int sum = prefix[end] - coords[previous];
                if (sum == 1) return 1;
                if (sum < best) best = sum;
            }
        }
        return best == 100001 ? -1 : best;
    }
};