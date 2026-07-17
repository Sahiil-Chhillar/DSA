class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0);

        for (auto& num : nums) freq[num]++;

        vector<long long> gcdCount(maxi + 1, 0);
        for (int g = maxi; g >= 1; g--) {
            long long cnt = 0;

            for (int multiple = g; multiple <= maxi; multiple += g) cnt += freq[multiple];
            gcdCount[g] = cnt * (cnt - 1) / 2;
            for (int multiple = 2 * g; multiple <= maxi; multiple += g) gcdCount[g] -= gcdCount[multiple];
        }
        vector<long long> prefix(maxi + 1, 0);
        for (int g = 1; g <= maxi; g++) {
            prefix[g] = gcdCount[g];

            if (g > 1) prefix[g] += prefix[g - 1];
        }

        vector<int> ans;
        for (long long query : queries) {
            int gcdValue = upper_bound(prefix.begin(),prefix.end(),query) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};