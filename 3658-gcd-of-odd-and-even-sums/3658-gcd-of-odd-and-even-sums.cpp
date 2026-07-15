class Solution {
public:
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};