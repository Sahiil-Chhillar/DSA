class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int end = *max_element(nums.begin(),nums.end());
        int sD;
        while(st <= end){
            int mid = st + (end - st)/2;

            int sum = 0;
            for(auto& num : nums){
                sum += (num + mid - 1) / mid;
            }

            if(sum <= threshold){
                sD  = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return sD;
    }
};