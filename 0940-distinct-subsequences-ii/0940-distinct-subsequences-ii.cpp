class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> dp;
    
    long long solve(int i, string &s) {
        if (i == s.size()) return 1; 
        
        if (dp[i] != -1) return dp[i];

        long long take = solve(i + 1, s);
        long long notTake = solve(i + 1, s);

        return dp[i] = (take + notTake) % MOD;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        dp.assign(n, -1);

        vector<long long> f(n + 1, 0);
        vector<int> last(26, -1);

        function<long long(int)> dfs = [&](int i) -> long long {
            if (i == n) return 1;
            if (f[i] != 0) return f[i];

            return f[i];
        };

        long long ans = 1;
        vector<long long> end(26, 0);

        for (char c : s) {
            int x = c - 'a';
            long long newSub = (ans - end[x] + MOD) % MOD;

            end[x] = ans;
            ans = (ans + newSub) % MOD;
        }

        return (ans - 1 + MOD) % MOD;
    }
};