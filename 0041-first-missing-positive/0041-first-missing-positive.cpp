// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         int missingNum = 1;
//         for(auto& num : nums) {
//             if(num == missingNum) missingNum++;
//             else if (num > missingNum) return missingNum;
//         }

//         return missingNum;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Put every number in its correct position i.e at index 0 -> 1 , 1 -> 2 and similarly so on 
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first incorrectly placed number
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};