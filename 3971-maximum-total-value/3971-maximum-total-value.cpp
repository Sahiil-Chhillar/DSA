class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        const long long MOD = 1e9 + 7;
        int n = value.size();

        auto count = [&](long long x) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                long long a = value[i];
                long long d = decay[i];
                if (a < x) continue;
                cnt += (a - x) / d + 1;
                if (cnt >= m) return cnt;
            }
            return cnt;
        };

        long long low = 1, high = 1e9;
        long long threshold = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= m) {
                threshold = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int i = 0; i < n; i++) {
            long long a = value[i];
            long long d = decay[i];
            if (a <= threshold) continue;
            long long k = (a - (threshold + 1)) / d + 1;
            long long last = a - (k - 1) * d;
            long long sum = k * (a + last) / 2;
            ans = (ans + sum % MOD) % MOD;
            used += k;
        }
        long long rem = m - used;
        ans = (ans + (rem % MOD) * (threshold % MOD)) % MOD;
        return (int)(ans % MOD);
    }
};