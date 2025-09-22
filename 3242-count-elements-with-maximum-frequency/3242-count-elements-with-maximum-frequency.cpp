class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int s = * max_element(nums.begin(),nums.end());
        vector<int> freq(s+1,0);
        for(auto& num : nums) freq[num]++;

        int maxFreq = *max_element(freq.begin(),freq.end());
        int ans = 0;
        for(auto& f : freq){
            if(f == maxFreq) ans += f;
        }

        return ans;
    }
};