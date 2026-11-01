class Solution {
public:
    long minimumMaxValue(int n, int index, int value) {
        if (n == 1)
            return value;
        if (value == 1)
            return -1;

        int left = index;
        int right = n - index - 1;

        if (left > 0) {
            if (value % 2 == 0) {
                if (value - 2L * left < 1) return -1;
            } 
            else {
                int p = smallestPrimeFactor(value);
                if (p == value) return -1;
                if (value - p - 2L * (left - 1) < 1) return -1;
            }
        }

        long ans = value;
        if (right > 0) {
            if (value % 2 == 0) {
                ans += 2L * right;
            } 
            else {
                int p = smallestPrimeFactor(value);
                if (p == value) ans = 2L * value;
                else  ans += p;
                ans += 2L * (right - 1);
            }
        }

        return ans;
    }

private:
    int smallestPrimeFactor(int x) {
        for (int i = 2; (long)i * i <= x; i++) {
            if (x % i == 0) return i;
        }

        return x;
    }
};