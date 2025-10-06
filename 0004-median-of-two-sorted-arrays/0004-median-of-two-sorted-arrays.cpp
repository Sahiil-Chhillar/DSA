class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int s1 = nums1.size(), s2 = nums2.size();
        vector<int> v;

        while (i < s1 && j < s2) {
            if (nums1[i] <= nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }

        while (i < s1) {
            v.push_back(nums1[i]);
            i++;
        }
        while (j < s2) {
            v.push_back(nums2[j]);
            j++;
        }

        int n = v.size();
        if (n % 2 != 0)
            return v[n / 2];
        else
            return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
};