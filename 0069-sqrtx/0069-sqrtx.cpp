class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int st = 1;
        int end = x/2;
        int ans = 1;
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(1LL * mid * mid == x) return mid;
            else if (1LL * mid * mid < x){
                st  = mid + 1;
                ans = mid;
            }
            else end = mid -1; 
        }
        return ans;
    }
};