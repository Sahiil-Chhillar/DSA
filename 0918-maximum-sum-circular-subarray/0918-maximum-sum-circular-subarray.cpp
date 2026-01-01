class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int total = 0;
//         int curMax = 0, maxSum = nums[0];
//         int curMin = 0, minSum = nums[0];
//         for (int x : nums) {
//             total += x;
//             curMax = max(x, curMax + x);
//             maxSum = max(maxSum, curMax);
//             curMin = min(x, curMin + x);
//             minSum = min(minSum, curMin);
//         }
//         if (maxSum < 0) return maxSum;
//         return max(maxSum, total - minSum);
//     }
// };