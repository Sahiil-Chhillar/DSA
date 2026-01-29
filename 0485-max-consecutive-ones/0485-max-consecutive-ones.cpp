class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int currCnt = 0;
        for(auto& num : nums){
            if(num == 1) currCnt++;
            else currCnt = 0;

            maxi = max(maxi,currCnt);
        }
        return maxi;
    }
};