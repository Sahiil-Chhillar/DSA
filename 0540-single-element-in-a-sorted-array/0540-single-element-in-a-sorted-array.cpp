class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // for (auto& num : nums) {
        //     freq[num]++;
        // }

        // for (auto& key : freq) {
        //     if (key.second == 1) return key.first;
        // }

        // return -1;

        int unique = 0;
        for(auto & num : nums) unique ^= num;
        return unique;

        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) left = mid + 2;
                else right = mid;
            }
            else {
                if (nums[mid] == nums[mid - 1]) left = mid + 1;
                else right = mid;
            }
        }
        return nums[right];
    }
};