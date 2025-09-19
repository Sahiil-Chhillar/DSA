class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> isPF(1001,false);
        for(auto& num : nums){
            for(int i = 2 ; i * i <= num;i++){
                if(num%i == 0){
                    isPF[i] = true;
                    while(num % i == 0) num /= i;
                }
            }
            if(num > 1) isPF[num] = true;
        }
        int cnt= 0;
        for(int i = 2 ; i<= 1000;i++) if(isPF[i]) cnt++;
        return cnt;
    }
};