class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        if(nums.empty()) return {};

        vector<int> res;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) cnt++;
            else {
                int times = min(cnt, k);
                while(times--) res.push_back(nums[i-1]);

                cnt = 1;
            }
        }
        int times = min(cnt, k);
        while(times--) res.push_back(nums.back());

        return res;
    }
};