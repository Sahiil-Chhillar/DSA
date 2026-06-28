// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         int maxElement = *max_element(arr.begin(), arr.end());
//         int n = arr.size();
//         return maxElement > n ? n : maxElement;
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();

        A.front() = 1;
        for (int i = 1; i < n; i++) A[i] = min(A[i], A[i - 1] + 1);
        return A.back();
    }
};