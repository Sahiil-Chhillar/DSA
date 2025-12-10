class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // vector<int> res;
        // for(int i = 0 ; i < queries.size();i++){
        //     nums[queries[i][1]] += queries[i][0];
        //     int sum = 0;
        //     for(auto& num : nums) if(num%2 == 0) sum+=num;
        //     res.push_back(sum);
        // }
        // return res;

        int sum = 0;
        for(auto& num : nums) if(num%2 == 0) sum+=num;

        vector<int> res;
        for(auto& q : queries){
            if(nums[q[1]] % 2 == 0) sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if(nums[q[1]] % 2 == 0) sum += nums[q[1]];
            res.push_back(sum);
        }

        return res;
    }
};