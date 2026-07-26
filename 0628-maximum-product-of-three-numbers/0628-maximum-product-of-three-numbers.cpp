class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fMax = -1e9, sMax = -1e9, tMax = -1e9;
        int fMin = 1e9, sMin = 1e9;

        for(auto& num : nums){
            if(num > fMax){
                tMax = sMax;
                sMax = fMax;
                fMax = num;
            }
            else if (num > sMax){
                tMax = sMax;
                sMax = num;
            }
            else if (num > tMax) tMax = num;


            if(num < fMin){
                sMin = fMin;
                fMin = num;
            }
            else if(num < sMin) sMin = num;
        }

        return fMax * sMax * tMax > fMax * fMin * sMin ? fMax * sMax * tMax : fMax * fMin * sMin;
    }
};