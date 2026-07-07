class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        int sum = 0;
        while(n){
            if(n%10){
                num = num * 10 + n%10;
                sum += n%10;
            }
            n/= 10;
        }
        int x = 0;
        while(num){
            x = x * 10 + num%10;
            num /= 10;
        }

        return (long long)x*sum;
    }
};