class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        vector<int> divV;
        int maxV = *max_element(nums.begin(),nums.end());
        for(int i = 1 ; i <= maxV;i++){
            divV.push_back(i);
        }
        int st = 0;
        int end = divV.size()-1;
        int sD;
        while(st <= end){
            int mid = st + (end - st)/2;

            int sum = 0;
            for(auto& num : nums){
                sum += (num + divV[mid] - 1) / divV[mid];
            }

            if(sum <= threshold){
                sD  = divV[mid];
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return sD;
    }
};