class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;
        for(int i = 0;  i< nums.size();i++){
            long long currSum = 0;
            for(int j = i ; j < nums.size();j++){
                currSum += nums[j];

                int last = currSum%10;

                long long temp = currSum;
                while(temp >= 10) temp /= 10;
                int first = temp;
                
                if(last == x && first == x) cnt++;
            }
        }
        return cnt;
    }
};