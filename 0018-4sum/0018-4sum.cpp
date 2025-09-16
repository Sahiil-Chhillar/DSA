class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;  

        sort(nums.begin(),nums.end());
        for(int i = 0 ; i< nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size();j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long searchSum = 1LL * target -(nums[i] + nums[j]);
                int st = j + 1;
                int end = nums.size() -1 ;

                while(st < end){
                    int sum = nums[st] + nums[end];
                    if(sum == searchSum) {
                        result.push_back({nums[i],nums[j],nums[st],nums[end]});
                        st++;
                        end--;

                        while(st < end && nums[st] == nums[st - 1]) st++;
                        while(st < end && nums[end] == nums[end + 1]) end--;
                    }else if(sum < searchSum) st++;
                    else end--;
                }
            }
        }

        return result;
    }
};