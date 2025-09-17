class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        // for(int i = 0 ; i< n; i++){
        //     int currSum = 0;
        //     for(int j = i ; j < n ; j++){
        //         currSum += nums[j];
        //         if(currSum == k) cnt++;
        //     }
        // }
        // return cnt;

        unordered_map<int,int> mp; // sum -> freq;
        mp[0] = 1;
        int currSum = 0;
        for(auto& num : nums){
            currSum += num;
            int toFind = currSum - k;
            if(mp.find(toFind) != mp.end()) cnt+= mp[toFind];
            mp[currSum]++;
        }
        return cnt;
    }
};