class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0 ;
        int digitProduct = 1;

        int temp = n;
        while(temp){
            int currDigit = temp%10;
            digitSum += currDigit;
            digitProduct *= currDigit;

            temp/=10;
        }

        return n % (digitSum + digitProduct) == 0;
    }
};