class Solution {
public:
    int maxProduct(int n) {
        int fMax = -1e9;
        int sMax = -1e9;

        while(n){
            int currDigit = n%10;

            if(currDigit > fMax){
                sMax = fMax;
                fMax = currDigit;
            }
            else if (currDigit > sMax) sMax = currDigit;

            n/=10;
        }

        return fMax*sMax;
    }
};