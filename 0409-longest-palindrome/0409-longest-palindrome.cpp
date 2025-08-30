class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int cnt = 0;
        int fg = 0;
        for (auto it : mp) {
            if (it.second % 2 == 0)
                cnt += it.second;
            if (it.second % 2 != 0) {
                fg=1;
                cnt+=(it.second-1);
            }
        }
        return cnt+fg;
    }
};