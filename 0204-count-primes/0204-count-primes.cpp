class Solution {
public:
    /* O(n * sqrt(n))
    bool isPrime(int n){
        for(int i = 2 ; i*i <= n ;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n<=1) return 0;
        int cnt = 0;
        for(int i = 2 ; i < n ;i++){
            if(isPrime(i)) cnt++;
        }
        return cnt;
    }
    */

    // sieve of eratosthenes
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool> isPrime(n,true);
        for(int i = 2; i * i <= n ; i++){
            if(isPrime[i]){
                for(int j = i * i ; j < n ; j+= i){
                    isPrime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2 ; i < n; i++){
            if(isPrime[i]) cnt++;
        }
        return cnt;
    }
};