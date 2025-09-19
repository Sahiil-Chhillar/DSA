class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> count;
        for(auto& num : nums){
            
            if(num%2 == 0) {
                count.insert(2);
                while(num%2 == 0) num /= 2;
            }


            for(int i = 3 ; i * i <= num ; i+=2){
                if(num% i == 0){
                    count.insert(i);
                    while(num%i == 0) num /= i;
                }
            }

            if(num > 1) count.insert(num);
        }
        return count.size();
    }
};