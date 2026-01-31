class Solution {
public:
    // int findMax(vector<int>& nums, int st, int end) {
    //     int maxNum = nums[st];
    //     while (st <= end) {
    //         maxNum = max(maxNum, nums[st]);
    //         st++;
    //     }
    //     return maxNum;
    // }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> result;

        // for (int i = 0; i < nums.size() - k + 1; i++) {
        //     int st = i;
        //     int end = st + k - 1;
        //     int max = findMax(nums, st, end);
        //     result.push_back(max);
        // }
        // return result;


        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i = 0 ; i< nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= i-k) pq.pop();
            if(pq.size() >= k) ans.push_back(pq.top().first);
        }

        return ans;
    }
};